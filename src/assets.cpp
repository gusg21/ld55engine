#include "ld55/assets.h"

#include <fstream>
#include <iostream>

#define BLOCK_SIZE 512

using namespace ld55;

static void ReadNullTerminated(std::ifstream &stream, char *buf) {
  char c;
  stream.read(&c, 1);
  int32_t index = 0;
  while (c != '\0') {
    buf[index] = c;
    index++;
    stream.read(&c, 1);
  }
}

Assets::Assets() {}

Assets::Assets(const std::string &can_file) {
  std::ifstream can_stream(can_file);

  char can_magic[4];
  can_stream.get(can_magic, 4);
  if (!(can_magic[0] == 'C' && can_magic[1] == 'A' && can_magic[2] == 'N' &&
        can_magic[3] == '!')) {
    printf("Malformed can file header!\n");
    return;
  }

  int32_t can_index_size = 0;
  can_stream.get((char *)&can_index_size, 5); // pretend the int is a char array

  // Load the index
  block_count_ = 0;
  for (int32_t i = 0; i < can_index_size; i++) {
    char name[512] = {0};
    ReadNullTerminated(can_stream, name);

    uint32_t block_start, block_length, byte_length;
    can_stream.get((char *)&block_start, 4);
    can_stream.get((char *)&block_length, 4);
    can_stream.get((char *)&byte_length, 4);
    printf("%s starts at block %d, %d blocks, %d bytes\n", name, block_start, block_length, byte_length);

    block_count_ += block_length;
  }

  // Allocate the data block
  data_ = new char[block_count_ * BLOCK_SIZE];

  // Read the blocks
  for (size_t i = 0; i < block_count_; i++) {
    can_stream.read(&data_[i * BLOCK_SIZE], // I love pointer arithmetic!
                    BLOCK_SIZE );
  }
}
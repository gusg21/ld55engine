#pragma once

#include <string>

namespace ld55
{
    class Assets {
    public:
        Assets();
        Assets(const std::string& can_file);

    private:
        int32_t block_count_ = 0;
        char* data_ = nullptr; 
    };
} // namespace ld55

project(stb_image VERSION 0.0.1 LANGUAGES CXX)

add_library(stb_image STATIC src/stb_image.cpp)
target_include_directories(stb_image PUBLIC include)
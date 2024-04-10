cmake_minimum_required(VERSION 3.21)
project(ld55_engine VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(external/glm)
add_subdirectory(external/SDL)

file(GLOB ${PROJECT_NAME}_SRC src/*.cpp src/*/*.cpp)
add_library(${PROJECT_NAME} ${${PROJECT_NAME}_SRC})

target_include_directories(${PROJECT_NAME} 
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        glm::glm
    PRIVATE
        SDL3::SDL3
)

target_link_libraries(${PROJECT_NAME} 
    PUBLIC
        glm::glm
    PRIVATE
        SDL3::SDL3

)
cmake_minimum_required(VERSION 3.21.2)

project(config-parser)


file (GLOB_RECURSE SOURCES "src/*.cc")

add_library(config-parser SHARED ${SOURCES})
set_target_properties(config-parser PROPERTIES
    CXX_STANDARD 20
    CXX_EXTENSIONS OFF
)

target_compile_options(config-parser PRIVATE -Wall -Wextra -Werror -pedantic #-fsanitize=address
)

target_link_libraries(config-parser PRIVATE utils)

target_include_directories(config-parser PUBLIC "include/")
cmake_minimum_required(VERSION 3.21.2)

project(utils)


file (GLOB_RECURSE SOURCES "src/*.cc")

add_library(utils SHARED ${SOURCES})
set_target_properties(utils PROPERTIES
    CXX_STANDARD 20
    CXX_EXTENSIONS OFF
)

target_compile_options(utils PRIVATE -Wall -Wextra -Werror -pedantic #-fsanitize=address
)

target_include_directories(utils PUBLIC "include/")
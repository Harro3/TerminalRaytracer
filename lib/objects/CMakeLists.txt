cmake_minimum_required(VERSION 3.21.2)

project(objects)


file (GLOB_RECURSE SOURCES "src/*.cc")

add_library(objects SHARED "src/hittable-list.cc" "src/sphere.cc" "src/object-renderer.cc")
set_target_properties(objects PROPERTIES
    CXX_STANDARD 20
    CXX_EXTENSIONS OFF
)

target_compile_options(objects PRIVATE -Wall -Wextra -Werror -pedantic #-fsanitize=address
)

target_link_libraries(objects PRIVATE utils)

target_include_directories(objects PUBLIC "include/")
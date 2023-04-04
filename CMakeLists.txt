cmake_minimum_required(VERSION 3.21.2)

project(terminal_raytracer)

# compile libraries
add_subdirectory(lib)

# add testsuite
add_subdirectory(tests)


add_executable(terminal_raytracer main.cc)
set_target_properties(terminal_raytracer PROPERTIES
    CXX_STANDARD 20
    CXX_EXTENSIONS OFF
)
target_compile_options(terminal_raytracer PRIVATE -Wall -Wextra -Werror -pedantic #-fsanitize=address
)

include_directories("lib/")

target_link_libraries(terminal_raytracer PRIVATE utils)
target_link_libraries(terminal_raytracer PRIVATE objects)
target_link_libraries(terminal_raytracer PRIVATE config-parser)
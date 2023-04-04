enable_testing()

find_package(GTest)

if (GTest_FOUND)
    file (GLOB_RECURSE SOURCES "src/*.cc")
    add_executable(check ${SOURCES})
    set_target_properties(check PROPERTIES EXCLUDE_FROM_ALL TRUE)

    target_link_libraries(check GTest::gtest GTest::gtest_main)

    # Linking the libraries
    target_link_libraries(check utils)
    target_link_libraries(check objects)
    target_link_libraries(check config-parser)

    target_include_directories(check PUBLIC "../lib/")

    set_target_properties(check PROPERTIES CXX_STANDARD 20 CXX_EXTENSIONS OFF)

    add_test(check check)

ENDIF()

cmake_minimum_required(VERSION 3.9)
project(stlmp_new)

set(CMAKE_CXX_STANDARD 17)

if (CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS "-Wall -std=c++17 -O3 -Wno-unknown-pragmas -Wno-sign-compare -Woverloaded-virtual -Wwrite-strings -Wno-unused")
    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g3")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif ()

include_directories(include)

add_library(stlmp
        include/stlmp.h
        src/algorithms/array_rotation.cpp
        )

# tests
add_executable(tests test/test.cpp)

target_link_libraries(tests stlmp)

include(CTest)
enable_testing()
add_test(test_name tests)

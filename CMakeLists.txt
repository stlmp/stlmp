cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(stlmp)

enable_language(C)
enable_language(CXX)

if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS         "-Wall -std=c++17 -Wno-unknown-pragmas -Wno-sign-compare -Woverloaded-virtual -Wwrite-strings -Wno-unused")
    set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g3")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

include_directories(
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/src/linked_list
    ${PROJECT_SOURCE_DIR}/src/stack
    ${PROJECT_SOURCE_DIR}/src/queue
    ${PROJECT_SOURCE_DIR}/src/sorting
    ${PROJECT_SOURCE_DIR}/src/tree
    ${PROJECT_SOURCE_DIR}/src/heap
    ${PROJECT_SOURCE_DIR}/src/disjoint_set
    )

add_library(
    stlmp
    src/main.cpp

    src/linked_list/ll.hpp
    src/linked_list/dll.hpp

    src/stack/stack.hpp

    src/queue/queue.hpp

    src/sorting/insertion.hpp

    src/tree/tree.hpp
    src/tree/bst.hpp

    src/heap/heap.hpp

    src/disjoint_set/disjoint_set.hpp
    )

set(GOOGLETEST_ROOT external/googletest/googletest CACHE STRING "Google Test source root")

include_directories(
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/include
    )

set(GOOGLETEST_SOURCES
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest-all.cc
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest_main.cc
    )

foreach(_source ${GOOGLETEST_SOURCES})
    set_source_files_properties(${_source} PROPERTIES GENERATED 1)
endforeach()

add_library(googletest ${GOOGLETEST_SOURCES})

add_executable(
    unit_tests

    test/main.cpp

    test/linked_list/test_ll.cpp
    test/linked_list/test_dll.cpp

    test/stack/test_stack.cpp

    test/queue/test_queue.cpp

    test/sorting/test_insertion.cpp

    test/tree/test_tree.cpp

    test/heap/test_heap.cpp

    test/disjoint_set/test_disjoint_set.cpp
    )

add_dependencies(unit_tests googletest)

target_link_libraries(
    unit_tests
    googletest
    stlmp
    pthread
    )

include(CTest)
enable_testing()

add_test(unit ${PROJECT_BINARY_DIR}/unit_tests)

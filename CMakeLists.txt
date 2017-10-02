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
    ${PROJECT_SOURCE_DIR}/src/search
    ${PROJECT_SOURCE_DIR}/src/tree
    ${PROJECT_SOURCE_DIR}/src/heap
    ${PROJECT_SOURCE_DIR}/src/disjoint_set
    ${PROJECT_SOURCE_DIR}/src/algorithms
    ${PROJECT_SOURCE_DIR}/src/graph
    )

file(GLOB LINKEDLIST src/linked_list/*.hpp)
file(GLOB TESTLINKEDLIST test/linked_list/*.cpp)

file(GLOB SORTING src/sorting/*.hpp)
file(GLOB TESTSORTING test/sorting/*.cpp)

file(GLOB SEARCH src/search/*.hpp)
file(GLOB TESTSEARCH test/search/*.cpp)

file(GLOB TREES src/tree/*.hpp)
file(GLOB TESTTREES test/tree/*.cpp)

file(GLOB GRAPHS src/graph/*.hpp)
file(GLOB TESTGRAPHS test/graph/*.cpp)

file(GLOB ALGORITHMS src/algorithms/*.hpp)
file(GLOB TESTALGORITHMS test/algorithms/*.cpp)

add_library(
    stlmp
    src/main.cpp

    ${LINKEDLIST}

    src/stack/stack.hpp

    src/queue/queue.hpp

    ${SORTING}

    ${TREES}

    ${GRAPHS}

    src/heap/heap.hpp

    src/disjoint_set/disjoint_set.hpp

    ${ALGORITHMS}
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

    ${TESTLINKEDLIST}

    test/stack/test_stack.cpp

    test/queue/test_queue.cpp

    ${TESTSORTING}

    ${TESTTREES}

    ${TESTGRAPHS}

    test/heap/test_heap.cpp

    test/disjoint_set/test_disjoint_set.cpp

    ${TESTALGORITHMS}
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

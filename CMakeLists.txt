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

file(GLOB LINKEDLIST src/linked_list/*.cpp)
file(GLOB SORTING src/sorting/*.cpp)
file(GLOB SEARCH src/search/*.cpp)
file(GLOB TREES src/tree/*.cpp)
file(GLOB GRAPHS src/graph/*.cpp)
file(GLOB ALGORITHMS src/algorithms/*.cpp)

add_library(stlmp
        include/stlmp.h

        # algorithms
        ${ALGORITHMS}

        # disjoint set
        src/disjoint_set/DisjointSet.cpp

        # graphs
#        ${GRAPHS}

        # queue
        src/queue/Queue.hpp

        # linked list
#        ${LINKEDLIST}
        src/linked_list/ll.hpp)

include(CTest)
enable_testing()

################# tests #################
########## algorithms
add_executable(test_array_rotation
        test/algorithms/test_array_rotation.cpp)
target_link_libraries(test_array_rotation stlmp)
add_test(ALGO_ARRAY_ROTATION test_array_rotation)

add_executable(test_flood_fill
        test/algorithms/test_flood_fill.cpp)
target_link_libraries(test_flood_fill stlmp)
add_test(ALGO_FLOOD_FILL test_flood_fill)

add_executable(test_count_inversions
        test/algorithms/test_count_inversions.cpp)
target_link_libraries(test_count_inversions stlmp)
add_test(ALGO_INVERSIONS_IN_ARRAY test_count_inversions)

########## disjoint set
add_executable(test_disjoint_set
        test/disjoint_set/test_disjoint_set.cpp)
target_link_libraries(test_disjoint_set stlmp)
add_test(DISJOINT_SET test_disjoint_set)

########## queue
add_executable(test_queue
        test/queue/test_queue.cpp)
target_link_libraries(test_queue stlmp)
add_test(QUEUE test_queue)

########## linked list
add_executable(test_linked_list
        test/linked_list/test_ll.cpp)
target_link_libraries(test_linked_list stlmp)
add_test(SINGLY_LINKED_LIST test_linked_list)

#add_executable(test_doubly_linked_list
#        test/linked_list/test_dll.cpp)
#target_link_libraries(test_doubly_linked_list stlmp)
#add_test(DOUBLY_LINKED_LIST test_doubly_linked_list)
# todo


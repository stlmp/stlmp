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

file(GLOB LINKEDLIST src/linked_list/*.hpp)
file(GLOB SORTING src/sorting/*.hpp)
file(GLOB SEARCH src/search/*.hpp)
file(GLOB HASHMAP src/hash/*.hpp)
file(GLOB TREES src/tree/*.hpp)
file(GLOB GRAPHS src/graph/*.hpp)
file(GLOB ALGORITHMS src/algorithms/*.cpp)

add_library(stlmp
        include/stlmp.h

        # algorithms
        ${ALGORITHMS}

        # disjoint set
        src/disjoint_set/DisjointSet.cpp

        # graphs
        ${GRAPHS}

        # queue
        src/queue/Queue.hpp

        # linked list
        ${LINKEDLIST}

        # stack
        src/stack/stack.hpp

        # hashmap
        ${HASHMAP}

        # heap
        src/heap/heap.hpp

        # searching algorithms
        ${SEARCH}

        # sorting algorithms
        ${SORTING}

        ${TREES}
        )

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

add_executable(test_doubly_linked_list
        test/linked_list/test_dll.cpp)
target_link_libraries(test_doubly_linked_list stlmp)
add_test(DOUBLY_LINKED_LIST test_doubly_linked_list)

########## graphs
add_executable(test_graph_adjacency_list
        test/graph/test_adjacency_list.cpp)
target_link_libraries(test_graph_adjacency_list stlmp)
add_test(GRAPH_ADJACENCY_LIST test_graph_adjacency_list)

add_executable(test_graph_adjacency_matrix
        test/graph/test_adjacency_matrix.cpp)
target_link_libraries(test_graph_adjacency_matrix stlmp)
add_test(GRAPH_ADJACENCY_MATRIX test_graph_adjacency_matrix)

########## stack
add_executable(test_stack
        test/stack/test_stack.cpp)
target_link_libraries(test_stack stlmp)
add_test(STACK test_stack)

########## heap
add_executable(test_heap
        test/heap/test_heap.cpp)
target_link_libraries(test_heap stlmp)
add_test(HEAP test_heap)

########## hashmap
add_executable(test_hashmap
        test/hashmap/test_hashmap.cpp)
target_link_libraries(test_hashmap stlmp)
add_test(HASHMAP test_hashmap)

########## search
add_executable(test_search_binary
        test/search/test_binary.cpp)
target_link_libraries(test_search_binary stlmp)
add_test(SEARCH_BINARY test_search_binary)

add_executable(test_search_fibonacci
        test/search/test_fibonacci.cpp)
target_link_libraries(test_search_fibonacci stlmp)
add_test(SEARCH_FIBONACCI test_search_fibonacci)

add_executable(test_search_jump
        test/search/test_jump.cpp)
target_link_libraries(test_search_jump stlmp)
add_test(SEARCH_JUMP test_search_jump)

########## sort
add_executable(test_sort_bubble
        test/sorting/test_bubble.cpp)
target_link_libraries(test_sort_bubble stlmp)
add_test(SORT_BUBBLE test_sort_bubble)

add_executable(test_sort_heap
        test/sorting/test_heap.cpp)
target_link_libraries(test_sort_heap stlmp)
add_test(SORT_HEAP test_sort_heap)

add_executable(test_sort_insertion
        test/sorting/test_insertion.cpp)
target_link_libraries(test_sort_insertion stlmp)
add_test(SORT_INSERTION test_sort_insertion)

add_executable(test_sort_merge
        test/sorting/test_merge.cpp)
target_link_libraries(test_sort_merge stlmp)
add_test(SORT_MERGE test_sort_merge)

add_executable(test_sort_quick
        test/sorting/test_quick.cpp)
target_link_libraries(test_sort_quick stlmp)
add_test(SORT_QUICK test_sort_quick)

add_executable(test_sort_radix
        test/sorting/test_radix.cpp)
target_link_libraries(test_sort_radix stlmp)
add_test(SORT_RADIX test_sort_radix)

add_executable(test_sort_selection
        test/sorting/test_selection.cpp)
target_link_libraries(test_sort_selection stlmp)
add_test(SORT_SELECTION test_sort_selection)

add_executable(test_sort_shell
        test/sorting/test_shell.cpp)
target_link_libraries(test_sort_shell stlmp)
add_test(SORT_SHELL test_sort_shell)

########## trees
add_executable(test_tree_simple
        test/tree/test_tree.cpp)
target_link_libraries(test_tree_simple stlmp)
add_test(TREE_SIMPLE test_tree_simple)

add_executable(test_tree_bst
        test/tree/test_tree_bst.cpp)
target_link_libraries(test_tree_bst stlmp)
add_test(TREE_BST test_tree_bst)

add_executable(test_tree_segment
        test/tree/test_tree_segment.cpp)
target_link_libraries(test_tree_segment stlmp)
add_test(TREE_SEGMENT test_tree_segment)


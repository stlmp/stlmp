<div align="center" style="margin: 20px">
  <img src="https://github.com/stlmp/stlmp/raw/master/stlmp.png">
</div>

<div align="center">

  <h1>stlmp</h1>
  <p>Implementation of data structures and algorithms in C++, like the Standard Template Library (STL). Tests written using <a href="https://code.google.com/p/googletest" target="_blank">googletest</a>, using the template <a href="https://github.com/bast/gtest-demo" target="_blank">bast/gtest-demo</a>.</p>
  <a href="https://travis-ci.org/stlmp/stlmp/builds" target="_blank"><img src="https://travis-ci.org/stlmp/stlmp.svg?branch=master" alt="Build Status"></a> 
  <a href="https://manparvesh.mit-license.org/" target="_blank"><img src="https://img.shields.io/badge/license-MIT-blue.svg" alt="License"></a> 
  
</div>


### Implementation tree
```
src
├── algorithms
│   └── flood_fill.hpp           # flood fill algorithm
│   └── array_rotation.hpp       # array rotation algorithm using reversing
├── disjoint_set
│   └── disjoint_set.hpp         # disjoint set implementation
├── graph
│   ├── adjacency_list.hpp       # graph implementation with adjacency list
│   ├── adjacency_matrix.hpp     # graph implementation with adjacency matrix
│   └── topological_sort.hpp     # topological sort (adjacency list)
├── heap
│   └── heap.hpp                 # heap implementation
├── linked_list
│   ├── dll.hpp                  # doubly linked list 
│   └── ll.hpp                   # singly linked list
├── main.cpp                     # ignore this file
├── queue
│   └── queue.hpp                # queue implementation
├── sorting
│   ├── bubble.hpp               # bubble sort
│   ├── insertion.hpp            # insertion sort
│   ├── merge.hpp                # merge sort
│   ├── quick.hpp                # quick sort
│   ├── radix.hpp                # radix sort
│   ├── selection.hpp            # selection sort
│   ├── heap.hpp                 # heap sort
│   └── shell.hpp                # shell sort
├── search
│   ├── binary.hpp               # binary search
│   ├── fibonacci.hpp            # fibonacci search
│   └── jump.hpp                 # jump search
├── stack
│   └── stack.hpp                # stack implementation
└── tree
    ├── bst.hpp                  # general tree implementation
    ├── segment_tree.hpp         # segment tree implementation
    └── tree.hpp                 # binary search tree
    └── redblacktree.hpp         # red black tree
    └── kruskels.hpp             # kruskels algorithm
```

### Building
 - Install C++17
```
$ sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
$ sudo apt-get update -qq
$ sudo apt-get install g++-6
$ sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-6 90
```
 - Run build script
```
$ ./build.sh
```
 - If there are any changes in the code and you need to build again, run the second script.
```
$ ./build_after_cmake.sh
```
### Plan
You can take a look at the implementation plan [here](https://github.com/stlmp/stlmp/blob/master/plan.md)

### License
[MIT](https://manparvesh.mit-license.org)

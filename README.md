<div align="center" style="margin: 20px">
  <img src="https://github.com/stlmp/stlmp/raw/master/stlmp.png">
</div>

<div align="center">

  <h1>stlmp</h1>
  <p>My own C++ STL-like implementation with some advanced data structures. Testing done using <a href="https://code.google.com/p/googletest" target="_blank">googletest</a>, using <a href="https://github.com/bast/gtest-demo" target="_blank">bast/gtest-demo</a>.</p>
  <a href="https://travis-ci.org/stlmp/stlmp/builds" target="_blank"><img src="https://travis-ci.org/stlmp/stlmp.svg?branch=master" alt="Build Status"></a> 
  <a href="https://manparvesh.mit-license.org/" target="_blank"><img src="https://img.shields.io/badge/license-MIT-blue.svg" alt="License"></a> 
  
</div>


#### Implementation tree
```
src
├── algorithms
│   └── flood_fill.hpp           # flood fill algorithm
├── disjoint_set
│   └── disjoint_set.hpp         # disjoint set implementation
├── graph
│   ├── adjacency_list.hpp       # graph implementation with adjacency list
│   └── adjacency_matrix.hpp     # graph implementation with adjacency matrix
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
│   └── insertion.hpp            # insertion sort
│   ├── merge.hpp                # merge sort
│   ├── quick.hpp                # quick sort
│   ├── radix.hpp                # radix sort
│   └── selection.hpp            # selection sort
├── stack
│   └── stack.hpp                # stack implementation
└── tree
    ├── bst.hpp                  # general tree implementation
    └── tree.hpp                 # binary search tree
```
### Plan
You can take a look at the implementation plan [here](https://github.com/stlmp/stlmp/blob/master/plan.md)

### License
[MIT](https://manparvesh.mit-license.org)

# stlmp
[![Build Status](https://travis-ci.org/manparvesh/stlmp.svg?branch=master)](https://travis-ci.org/manparvesh/stlmp/builds)  [![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://manparvesh.mit-license.org)  

My own C++ STL-like implementation with some advanced data structures. Testing done using [googletest](https://code.google.com/p/googletest), using [bast/gtest-demo](https://github.com/bast/gtest-demo).

#### Implementation tree
```
src
├── disjoint_set
│   └── disjoint_set.hpp         # disjoint set implementation
├── heap
│   └── heap.hpp                 # heap implementation
├── linked_list
│   ├── dll.hpp                  # doubly linked list 
│   └── ll.hpp                   # singly linked list
├── main.cpp                     # ignore this file
├── queue
│   └── queue.hpp                # queue implementation
├── sorting
│   └── insertion.hpp            # insertion sort
├── stack
│   └── stack.hpp                # stack implementation
└── tree
    ├── bst.hpp                  # general tree implementation
    └── tree.hpp                 # binary search tree
```
### Plan
You can take a look at the implementation plan [here](plan.md)

### License
[MIT](https://manparvesh.mit-license.org)

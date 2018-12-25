<div align="center" style="margin: 20px">
  <img src="https://github.com/stlmp/stlmp/raw/master/stlmp.png">
</div>

<div align="center">

  <h1>stlmp</h1>
  <p>Data Structures and Algorithms library in C++</p>
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
```

### Building
 - Run build script
```
$ ./build.sh
```
 - If there are any changes in the code and you need to build again, run the second script.
```
$ ./build_after_cmake.sh
```
### Plan
You can take a look at the implementation plan [in the issues](https://github.com/stlmp/stlmp/issues)

### License
[MIT](https://manparvesh.mit-license.org)

```
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
```

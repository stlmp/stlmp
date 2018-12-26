#ifndef __STLMP__
#define __STLMP__

#include <cstdlib>
#include <vector>
#include <map>

namespace stlmp {
    namespace algorithms {
        /**
         * Rotate array by given number of rotations
         * */
        void RotateArray(int *array, int rotations, int arraySize);

        void FloodFill(int screen[][8], int x, int y, int newC);

        int CountInversionsInArray(int array[], int n);
    }

    namespace DisjointSet {
        class DisjointSet {
        private:
            int *id, *size, count;
        public:
            explicit DisjointSet(int n);

            int getCount();

            int find(int n);

            void merge(int x, int y);

            bool connected(int x, int y);

            ~DisjointSet() {
                delete[] id;
                delete[] size;
            }
        };
    }

    namespace LinkedList {
        /**
         * The node class for linked list
         * */
        template<class T>
        class LLNode {
        public:
            T data;
            LLNode *next;

            explicit LLNode<T>(T newData) : data(newData), next(NULL) {}
        };

        /**
         * The SinglyLinkedList class
         * */
        template<class T>
        class SinglyLinkedList {
        private:
            LLNode<T> *head;

            void move_next(LLNode<T> **head_ref);

        public:
            // constructor that creates a new list with head as a new node with given data
            explicit SinglyLinkedList(T newData) : head(newData == NULL ? NULL : new LLNode<T>(newData)) {}

            LLNode<T> *getHead() {
                return head;
            }

            // print this list
            void printList();

            // get length of linked list
            int getLength();

            // push at the starting of a linked list
            void push(T data);

            // append new node at the end
            void append(T data);

            // insert after the node with given data
            void insertAfter(LLNode<T> *prev_node, T newData);

            // delete the node with the given data
            void deleteNodeWithData(T data);

            // get position of a key in linked list
            int searchKey(T key);

            // compare to another list
            bool compareTo(SinglyLinkedList<T> *anotherList);

            // reverse this list
            void reverseList();
        };


        template<class T>
        SinglyLinkedList<T> *create_list_from_array(int length, T arr[]);
    }

    namespace Queue {
        template<class T>
        struct Queue {
            stlmp::LinkedList::LLNode<T> *head;
            int size; // number of elements in the queue

            Queue() : size(0) {}

            void push(T new_data);

            void print();

            T pop();

            T peek();
        };

        template<class T>
        int get_size(Queue<T> *s) {
            return s->size;
        }
    }

    namespace Stack {
        template<class T>
        class Stack {
        private:
            LinkedList::LLNode<T> *top;
            int capacity; // number of elements the stack can contain
            int size; // number of elements in the stack

        public:
            Stack() : capacity(10), size(0) {}

            explicit Stack(int cap) : capacity(cap), size(0) {}

            void push(T new_data);

            void print();

            T pop();

            T peek();

            int getSize();

            int getCapacity();

            bool empty();
        };
    }

    namespace Graph {
        namespace AdjacencyList {
            template<typename T>
            class Graph {
            private:
                int count;
                std::map<int, std::vector<T> > connections;
                std::vector<T> vertices;
                bool *visited;

                void topologicalSortUtil(int v, bool *visited, Stack::Stack<int> *st);

            public:
                Graph(T vertices[], int count);

                void connect(int i, int j);

                void connect_both_sides(int i, int j);

                bool contains(std::vector<int> v, int n);

                bool bfs(int i, int j);

                void dfs(int i);

                // check if the vertices at i and j are connected.
                bool connected(int i, int j);

                void print_graph();

                int connected_components();

                Stack::Stack<T> topologicalSort();

                std::pair<std::vector<int>, std::vector<int> > shortestPathFromVertex(int s);
            };
        }

        namespace AdjacencyMatrix {
            template<typename T>
            class Graph {
            private:
                int count;
                bool **connections;
                T *vertices;
                bool *visited;
            public:
                Graph(T vertices[], int count);

                void connect(int i, int j);

                void connect_both_sides(int i, int j);

                bool bfs(int i, int j);

                void dfs(int i);

                // check if the vertices at i and j are connected.
                bool connected(int i, int j);

                int connected_components();
            };
        }
    }

    namespace Heap {
        template<typename T>
        class Heap {
        private:
            T *arr;
            int size;
            int capacity;
            int type; // if 1, max heap else if -1 min heap
        public:
            Heap() : arr(NULL), size(0), capacity(0), type(0) {}

            Heap(int capacity, int type) : arr(new T[capacity]), size(0), capacity(capacity), type(type) {}

            // get private values
            int get_size() { return this->size; }

            int get_capacity() { return this->capacity; }

            int get_type() { return this->type; }

            // util functions
            // get index of parent from child index
            int get_parent(int child_index);

            bool has_left_child(int parent_index);

            bool has_right_child(int parent_index);

            // get index of left child from parent's index
            int get_left_child(int parent_index);

            // get index of left child from parent's index
            int get_right_child(int parent_index);

            // get max / min, depending on the type of heap
            // get minimum from min heap
            T get_min();

            // get maximum from max heap
            T get_max();

            // takes location of element as input and heapifies our array downwards
            // considering max heap
            void down(int parent_index);

            bool is_full() {
                return this->size == this->capacity;
            }

            bool is_empty() {
                return this->size == 0;
            }

            void resize();

            void insert(T data);

            // another constructor to create a heap from an array
            Heap(T ar[], int capacity, int type) : arr(new T[capacity]), size(capacity), capacity(capacity), type(type) {
                for (int i = 0; i < capacity; i++) this->arr[i] = ar[i];
                for (int i = (capacity - 1) / 2; i >= 0; i--) down(i);
            }

            void print();

            bool is_heap();
        };
    }

    namespace Search {
        template <class T>
        class BinarySearch {
        public:
            T search(int arrayLength, T ar[], T target);
        };

        template <class T>
        class FibonacciSearch {
        public:
            T search(int arrayLength, T ar[], T target);
        };

        template <class T>
        class JumpSearch {
        public:
            T search(int arrayLength, T ar[], T target);
        };
    }

    namespace Sorting {
        template <class T>
        class BubbleSort {
        public:
            void sort(int length, T v[]);
        };

        template <class T>
        class HeapSort {
        private:
            void heapify(T v[], int length, int i);
        public:
            void sort(int length, T v[]);
        };

        template <class T>
        class InsertionSort {
        public:
            void sort(int length, T v[]);
        };
    }
}

#include "../src/linked_list/ll.hpp"

#include "../src/queue/Queue.hpp"

#include "../src/graph/adjacency_list.hpp"
#include "../src/graph/adjacency_matrix.hpp"

#include "../src/stack/stack.hpp"

#include "../src/heap/heap.hpp"

#include "../src/search/binary.hpp"
#include "../src/search/fibonacci.hpp"
#include "../src/search/jump.hpp"

#include "../src/sorting/bubble.hpp"
#include "../src/sorting/heap_sort.hpp"
#include "../src/sorting/insertion.hpp"

#endif

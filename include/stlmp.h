#ifndef __STLMP__
#define __STLMP__

#include <cstdlib>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
#include <string>

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

        template<class T>
        class DLLNode {
        public:
            T data;
            DLLNode *next;
            DLLNode *prev;

            explicit DLLNode(T data) : data(data), next(NULL), prev(NULL) {}
        };

        template<class T>
        class DoublyLinkedList {
        private:
            DLLNode<T> *head;

            void move_next(DLLNode<T> **head_ref);

            void move_prev(DLLNode<T> **head_ref);

        public:
            // constructor that creates a new list with head as a new node with given data
            explicit DoublyLinkedList(T newData) : head(newData == NULL ? NULL : new DLLNode<T>(newData)) {}

            DLLNode<T> *getHead() {
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
            void insertAfter(DLLNode<T> *prev_node, T newData);

            // delete the node with the given data
            void deleteNodeWithData(T data);

            // get position of a key in linked list
            int searchKey(T key);

            // compare to another list
            bool compareTo(DoublyLinkedList<T> *anotherList);

            // reverse this list
            void reverseList();
        };

        template<class T>
        DoublyLinkedList<T> *create_doubly_linked_list_from_array(int length, T arr[]);
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

    namespace HashMap {
        // some popular hash functions
        unsigned long long djb2(const std::string& input);
        unsigned long long sbdm(const std::string& input);

        template<typename K, typename V>
        class HashMap{
        private:
            std::pair<K, V> **table;
            bool *should_check;
            int size;
            int capacity;
            unsigned long long (*primary_hash)(const K& key);
            unsigned long long (*secondary_hash)(const K& key);

            void reset_arrays();
            int find_index(const K& key);
            void resize_table();

        public:
            HashMap();

            HashMap(int capacity, unsigned long long (*hash_function)(K, int), unsigned long long (*secondary_hash)(K, int) = nullptr);

            //big 3
            HashMap(const HashMap<K, V>& other);

            ~HashMap();

            const HashMap<K, V>& operator=(const HashMap<K, V>& other);

            void insert(const K& key, const V& value);

            V get(const K& key);

            V remove(const K& key);
        };
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
            Heap(T ar[], int capacity, int type) : arr(new T[capacity]), size(capacity), capacity(capacity),
                                                   type(type) {
                for (int i = 0; i < capacity; i++) this->arr[i] = ar[i];
                for (int i = (capacity - 1) / 2; i >= 0; i--) down(i);
            }

            void print();

            bool is_heap();
        };
    }

    namespace Search {
        template<class T>
        class BinarySearch {
        public:
            T search(int arrayLength, T ar[], T target);
        };

        template<class T>
        class FibonacciSearch {
        public:
            T search(int arrayLength, T ar[], T target);
        };

        template<class T>
        class JumpSearch {
        public:
            T search(int arrayLength, T ar[], T target);
        };
    }

    namespace Sorting {
        template<class T>
        class BubbleSort {
        public:
            void sort(int length, T v[]);
        };

        template<class T>
        class HeapSort {
        private:
            void heapify(T v[], int length, int i);

        public:
            void sort(int length, T v[]);
        };

        template<class T>
        class InsertionSort {
        public:
            void sort(int length, T v[]);
        };

        template<class T>
        class MergeSort {
        private:
            void _merge(T v[], int left, int mid, int right);

            void _merge_sort(T v[], int left, int right);

        public:
            void sort(int length, T v[]);
        };

        template<class T>
        class QuickSort {
        private:
            int _partition(T v[], int left, int right);

            void _quick(T v[], int left, int right);

        public:
            void sort(int length, T v[]);
        };

        template<class T>
        class RadixSort {
        private:
            void _count_sort(T arr[], int length, int exp);

        public:
            void sort(int length, T v[]);
        };

        template<class T>
        class SelectionSort {
        private:
            T _get_min(int length, T v[], int i);

        public:
            void sort(int length, T v[]);
        };

        template<class T>
        class ShellSort {
        public:
            void sort(int length, T v[]);
        };
    }

    namespace Tree {
        template<class T>
        struct TreeNode {
            T data;
            TreeNode *left_child;
            TreeNode *right_child;

            TreeNode(T new_data) : data(new_data), left_child(NULL), right_child(NULL) {};

            void insertLeft(T new_data);

            void insertRight(T new_data);
        };

        template<class T>
        int get_length(TreeNode<T> *top);

        namespace SegmentTree {
            class SegmentTree {
            private:
                int *st;
                int *ar;
                int len;
                int sz; //size of segment tree

                // function to get middle of a segment
                int _get_mid(int start, int end) {
                    return start + (end - start) / 2;
                }

                // util function to construct segment tree
                int _get_sum(int start, int end, int q_start, int q_end, int current) {
                    if (q_start <= start && q_end >= end) return st[current];

                    // outside range
                    if (end < q_start || start > q_end) return 0;

                    int mid = _get_mid(start, end);
                    return _get_sum(start, mid, q_start, q_end, 2 * current + 1) +
                           _get_sum(mid + 1, end, q_start, q_end, 2 * current + 2);
                }

                int _construct(int *v, int start, int end, int current) {
                    // if there is 1 element in stray, store in current
                    // node and return
                    if (start == end) {
                        st[current] = v[start];
                        return v[start];
                    }

                    // for more elements, recur for left & right subtrees
                    // store the sum for values in this node
                    int mid = _get_mid(start, end);
                    st[current] = _construct(v, start, mid, current * 2 + 1) +
                                  _construct(v, mid + 1, end, current * 2 + 2);
                    return st[current];
                }

                void _update_value(int start, int end, int i, int difference, int current) {
                    if (i < start || i > end) return;
                    st[current] = st[current] + difference;
                    if (end != start) {
                        int mid = _get_mid(start, end);
                        _update_value(start, mid, i, difference, 2 * current + 1);
                        _update_value(mid + 1, end, i, difference, 2 * current + 2);
                    }
                }

            public:
                void print() {
                    std::cout << "Printing segment tree" << std::endl;
                    int n = this->sz;
                    for (int i = 0; i < n; i++) std::cout << st[i] << " ";
                    std::cout << std::endl;
                }

                int get(int n) {
                    return st[n];
                }

                int get_sum(int start, int end) {
                    if (start < 0 || end > this->len - 1 || start > end) return -1;
                    return _get_sum(0, this->len - 1, start, end, 0);
                }

                void update(int i, int new_val) {
                    if (i < 0 || i > this->len - 1) return;
                    int difference = new_val - ar[i];
                    ar[i] = new_val;

                    // update segment tree
                    _update_value(0, this->len - 1, i, difference, 0);
                }

                SegmentTree(int *v, int n) {
                    ar = new int[n];
                    this->len = n;
                    for (int i = 0; i < n; i++) ar[i] = v[i];
                    // construct tree
                    // height of tree
                    this->sz = 0;
                    int h = (int) ceil(std::log2(n));
                    int max_size = 2 * (int) std::pow(2, h) - 1;
                    this->sz = max_size;

                    // allocate memory
                    st = new int[max_size];
                    _construct(v, 0, n - 1, 0);
                }

            };
        }

        namespace BST {
            template<class T>
            struct BSTNode {
                T data;
                BSTNode *left_child;
                BSTNode *right_child;

                BSTNode(T new_data) : data(new_data), left_child(NULL), right_child(NULL) {};
            };

            template<class T>
            class BST {
            private:
                BSTNode<T> *node;

                // helper functions
                int _get_length(BSTNode<T> *node);

                void _insert(BSTNode<T> *node, T new_data);

                void _print(BSTNode<T> *node);

                void _print_post_order(BSTNode<T> *node);

                void _print_pre_order(BSTNode<T> *node);

                int _count_nodes(BSTNode<T> *node);

                bool _find(BSTNode<T> *node, T data);

                void _print_max_path(BSTNode<T> *node);

                T _get_max(BSTNode<T> *node);

                T _get_min(BSTNode<T> *node);

                BSTNode<T> *_get_min_node(BSTNode<T> *node);

                BSTNode<T> *_delete_value(BSTNode<T> *root, T del_data);

                int _get_count(BSTNode<T> *node);

                void _level_order(BSTNode<T> *node);

            public:
                BST() : node(NULL) {}

                BST(T new_data) : node(new BSTNode<T>(new_data)) {}

                ~BST() {
                    delete node;
                }

                T data();

                void insert(T new_data);

                int get_length();

                void print();

                void print_post_order();

                void print_pre_order();

                T get_max();

                T get_min();

                int count_nodes();

                bool find(T data);

                void print_max_path();

                void delete_value(T del_data);

                int get_count();

                void level_order();
            };
        }
    }
}

#include "../src/linked_list/ll.hpp"
#include "../src/linked_list/dll.hpp"

#include "../src/queue/Queue.hpp"

#include "../src/graph/adjacency_list.hpp"
#include "../src/graph/adjacency_matrix.hpp"

#include "../src/stack/stack.hpp"

#include "../src/hashmap/hashmap.hpp"

#include "../src/heap/heap.hpp"

#include "../src/search/binary.hpp"
#include "../src/search/fibonacci.hpp"
#include "../src/search/jump.hpp"

#include "../src/sorting/bubble.hpp"
#include "../src/sorting/heap_sort.hpp"
#include "../src/sorting/insertion.hpp"
#include "../src/sorting/merge.hpp"
#include "../src/sorting/quick.hpp"
#include "../src/sorting/radix.hpp"
#include "../src/sorting/selection.hpp"
#include "../src/sorting/shell.hpp"

#include "../src/tree/tree.hpp"
#include "../src/tree/bst.hpp"

#endif

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
}

#include "../src/linked_list/ll.hpp"

#include "../src/queue/Queue.hpp"

#include "../src/graph/adjacency_list.hpp"
#include "../src/graph/adjacency_matrix.hpp"

#include "../src/stack/stack.hpp"

#endif

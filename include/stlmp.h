#ifndef __STLMP__
#define __STLMP__

#include <cstdlib>

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
}

#include "../src/linked_list/ll.hpp"
#include "../src/queue/Queue.hpp"

#endif
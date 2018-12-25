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
        template<class T>
        class LLNode {
        public:
            T data;
            LLNode *next;

            explicit LLNode<T>(T newData) : data(newData), next(NULL) {}
        };

        template<class T>
        class SinglyLinkedList {
        private:
            LLNode<T> head;
        public:
            explicit SinglyLinkedList(T newData) : head(new LLNode(newData)) {}

            void printList(LLNode<T> head);

            int getLength(LLNode<T> head);
        };


        template<class T>
        LLNode<T> *create_list_from_array(int length, T arr[]);

        template<class T>
        void push(LLNode<T> **head_ref, T data);

        template<class T>
        void insert_after(LLNode<T> *prev_node, T data);

        template<class T>
        void append(LLNode<T> **head_ref, T data);

        template<class T>
        void delete_node_with_data(LLNode<T> **head_ref, int data);

        template<class T>
        int search_key(LLNode<T> *head, T key);

        template<class T>
        void reverse_list(LLNode<T> **head_ref);

        template<class T>
        void move_next(LLNode<T> **head_ref);

        template<class T>
        bool compare_lists(LLNode<T> *head1, LLNode<T> *head2);
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

#endif
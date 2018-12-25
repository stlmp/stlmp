#ifndef __STLMP__
#define __STLMP__

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
        struct ll_node{
            T data;
            ll_node *next;
        };

        template<class T>
        ll_node<T> *create_node(T new_data);

        template<class T>
        void print_list(struct ll_node<T> *head);

        template<class T>
        int get_length(struct ll_node<T> *head);

        template<class T>
        ll_node<T> *create_list_from_array(int length, T arr[]);

        template<class T>
        void push(ll_node<T> **head_ref, T data);

        template<class T>
        void insert_after(ll_node<T> *prev_node, T data);

        template<class T>
        void append(ll_node<T> **head_ref, T data);

        template<class T>
        void delete_node_with_data(ll_node<T> **head_ref, int data);

        template<class T>
        int search_key(ll_node<T> *head, T key);

        template<class T>
        void reverse_list(ll_node<T> **head_ref);

        template<class T>
        void move_next(ll_node<T> **head_ref);

        template<class T>
        bool compare_lists(ll_node<T> *head1, ll_node<T> *head2);
    }
}

#endif
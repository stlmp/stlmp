#include "stlmp.h"

using namespace stlmp::Heap;

template<typename T>
int Heap<T>::get_parent(int child_index) {
    if (child_index <= 0 || child_index >= this->capacity) return -1;
    return (child_index - 1) / 2;
}

template<typename T>
bool Heap<T>::is_heap() {
    int i = 0;
    // assuming max heap
    for (int j = 0; j < this->size; j++) {
        if (this->has_left_child(j) && this->arr[this->get_left_child(j)] > this->arr[j]) return false;
        if (this->has_right_child(j) && this->arr[this->get_right_child(j)] > this->arr[j]) return false;
    }
    return true;
}

template<typename T>
void Heap<T>::print() {
    cout << "Printing heap: " << endl;
    for (int i = 0; i < this->size; i++) cout << this->arr[i] << " ";
    cout << endl;
}

template<typename T>
void Heap<T>::insert(T data) {
    if (this->is_full()) this->resize();
    this->size++;
    int i = this->size - 1;
    while (i > 0 && data > this->arr[get_parent(i)]) {
        this->arr[i] = this->arr[get_parent(i)];
        i = get_parent(i);
    }
    this->arr[i] = data;
}

template<typename T>
void Heap<T>::resize() {
    T *old_array = this->arr;
    this->arr = static_cast< T * > (malloc(sizeof(T) * this->capacity * 2));
    if (this->arr == NULL) {
        cout << "Memory error" << endl;
        return;
    }
    for (int i = 0; i < this->capacity; i++) this->arr[i] = old_array[i];
    this->capacity *= 2;
    delete[] old_array;
}

template<typename T>
void Heap<T>::down(int parent_index) {
    int left_child_index = get_left_child(parent_index), right_child_index = get_right_child(parent_index);
    if (left_child_index == -1 && right_child_index == -1) return;

    // everything is valid, so let's proceed to finding the next max element that can be swapped with the parent
    int max_element = parent_index;
    if (left_child_index != -1) {
        if (arr[left_child_index] > arr[parent_index]) max_element = left_child_index;
        else max_element = parent_index;
    } else max_element = parent_index;

    if (right_child_index != -1) {
        if (arr[right_child_index] > arr[max_element]) max_element = right_child_index;
    }

    if (max_element == -1) return;

    // swap max_element with parent
    if (max_element != parent_index) {
        int temp = arr[max_element];
        arr[max_element] = arr[parent_index];
        arr[parent_index] = temp;
    }

    down(max_element);
}

template<typename T>
T Heap<T>::get_max() {
    // returns null if array is empty or heap type is min
    if (this->size == 0 || this->type == -1) return '\0';
    return this->arr[0];
}

template<typename T>
T Heap<T>::get_min() {
    // returns null if array is empty or heap type is max
    if (this->size == 0 || this->type == 1) return '\0';
    return this->arr[0];
}

template<typename T>
bool Heap<T>::has_left_child(int parent_index) {
    return (parent_index * 2 + 1 < this->size) && (parent_index >= 0);
}

template<typename T>
int Heap<T>::get_right_child(int parent_index) {
    int right_child_index = parent_index * 2 + 2;
    if (!has_right_child(parent_index)) return -1;
    return right_child_index;
}

template<typename T>
int Heap<T>::get_left_child(int parent_index) {
    int left_child_index = parent_index * 2 + 1;
    if (!has_left_child(parent_index)) return -1;
    return left_child_index;
}

template<typename T>
bool Heap<T>::has_right_child(int parent_index) {
    return (parent_index * 2 + 2 < this->size) && (parent_index >= 0);
}

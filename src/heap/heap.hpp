#include <iostream>
using namespace std;

template<typename T>
class heap {
private:
	T *arr;
	int size;
	int capacity;
	int type; // if 1, max heap else if -1 min heap
public:
	heap() : arr(NULL), size(0), capacity(0), type(0) {}
	heap(int capacity, int type) : arr(new T[capacity]), size(0), capacity(capacity), type(type) {}

	// get private values
	int get_size(){ return this->size; }
	int get_capacity(){ return this->capacity; }
	int get_type(){ return this->type; }

	// util functions
	// get index of parent from child index
	int get_parent(int child_index){
		if(child_index <=0 || child_index >= this->capacity) return -1;
		return (child_index-1)/2;
	}

	// get index of left child from parent's index
	int get_left_child(int parent_index){
		int left_child_index = parent_index * 2 + 1;
		if(left_child_index >= this->size) return -1;
		return left_child_index;
	}

	// get index of left child from parent's index
	int get_right_child(int parent_index){
		int right_child_index = parent_index * 2 + 2;
		if(right_child_index >= this->size) return -1;
		return right_child_index;
	}

	// get max / min, depending on the type of heap
	// get minimum from min heap
	T get_min(){
		// returns null if array is empty or heap type is max
		if(this->size == 0 || this->type == 1) return '\0';
		return this->arr[0];
	}
	// get maximum from max heap
	T get_max(){
		// returns null if array is empty or heap type is min
		if(this->size == 0 || this->type == -1) return '\0';
		return this->arr[0];
	}

	// takes location of element as input and heapifies our array downwards
	// considering max heap
	void down(int parent_index){
		int left_child_index = get_left_child(), right_child_index = get_right_child();
		if(left_child_index == -1 && right_child_index == -1) return;

		// everything is valid, so let's proceed to finding the next max element that can be swapped with the parent
		int max_element;
		if(left_child_index != -1 && arr[left_child_index] > arr[parent_index]) max_element = left_child_index;
		else max_element = parent_index;

		if(right_child_index != -1 && arr[right_child_index] > arr[max_element]) max_element = right_child_index;

		// swap max_element with parent
		if(max_element != parent_index){
			int temp = arr[max_element];
			arr[max_element] = arr[parent_index];
			arr[parent_index] = temp;
		}

		down(max_element);
	}
};

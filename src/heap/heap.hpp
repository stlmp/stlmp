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
	int size(){ return this->size; }
	int capacity(){ return this->capacity; }
	int type(){ return this->type; }

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


};

#include <iostream>
using namespace std;

template<typename T>
class heap {
private:
	int *ar;
	int size;
	int capacity;
	int type; // if 1, max heap else if -1 min heap
public:
	heap() : ar(NULL), size(0), capacity(0), type(0) {}
	heap(int capacity, int type) : ar(new int[capacity]), size(0), capacity(capacity), type(type) {}

	// get private values
	int size(){ return this->size; }
	int capacity(){ return this->capacity; }
	int type(){ return this->type; }

	// util functions
	int get_parent(int child){
		if(child <=0 || child >= this->capacity) return -1;
		return (i-1)/2;
	}
};

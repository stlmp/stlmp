#include "stlmp.h"
using namespace std;
using namespace stlmp::LinkedList;
using namespace stlmp::Stack;

template<class T>
T Stack<T>::pop() {
	if(size == 0){
		cout << "Stack is empty, can't pop" << endl;
		return '\0';
	}
	T data = this->top->data;
	this->top = this->top->next;
	size--;
	return data;
}

template<class T>
int Stack<T>::getCapacity() {
	return capacity;
}

template<class T>
int Stack<T>::getSize() {
	return size;
}

template<class T>
T Stack<T>::peek() {
	return this->top->data;
}

template<class T>
void Stack<T>::print() {
	LLNode<T> *temp_node = this->top;
	if(size == 0){
		cout << "Stack is empty" << endl;
		return;
	}
	cout << "Printing stack:" << endl;
	for(int i=0;i<this->size;i++){
		cout << temp_node->data << ' ';
		temp_node = temp_node->next;
	}
	cout << endl;
}

template<class T>
void Stack<T>::push(T new_data) {
	if(size == capacity){
		cout << "Stack is full! Cannot push new element" << endl;
		return;
	}
	LLNode<T> *new_node = new LLNode<T>(new_data);
	LLNode<T> *temp_node = this->top;
	new_node->next = temp_node;
	this->top = new_node;
	size++;
}

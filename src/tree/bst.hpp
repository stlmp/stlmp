#include <bits/stdc++.h>
using namespace std;

template<class T>
struct bst_node{
	T data;
	bst_node *left_child;
	bst_node *right_child;

	bst_node(T new_data) : data(new_data), left_child(NULL), right_child(NULL) {};

	void insert(T new_data){
		bst_node<T> *new_node = new bst_node<T>(new_data);
		bst_node<T> *temp = this;
		// if(temp->data < new_data)
	}
};

template<class T>
int get_length(bst_node<T> *top){
	if(top == NULL) return 0;
	return 1 + max(get_length(top->left_child), get_length(top->right_child));
}

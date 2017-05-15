#include <bits/stdc++.h>
using namespace std;

template<class T>
struct ll_node{
	T data;
	ll_node *next;
};

template<class T>
ll_node<T> *create_node(T new_data){
	ll_node<T> *new_node = NULL;
	new_node = new ll_node<T>;
	new_node->data = new_data;
	new_node->next = NULL;
	return new_node;
}

template<class T>
void print_list(struct ll_node<T> *head){
	while(head){
		cout << head->data << endl;
		head = head->next;
	}
}

template<class T>
int get_length(struct ll_node<T> *head){
	int length = 0;
	while(head){
		length++;
		cout << head->data << " ";
		head = head->next;
	}
	return length;
}



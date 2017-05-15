#include <bits/stdc++.h>
using namespace std;

template<class T>
struct ll_node{
	T data;
	ll_node *next;
};

// assign value to node and return
template<class T>
ll_node<T> *create_node(T new_data){
	ll_node<T> *new_node = NULL;
	new_node = new ll_node<T>;
	new_node->data = new_data;
	new_node->next = NULL;
	return new_node;
}

// print list
template<class T>
void print_list(struct ll_node<T> *head){
	while(head){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

// get length of list
template<class T>
int get_length(struct ll_node<T> *head){
	int length = 0;
	cout << "List:\n";
	while(head){
		length++;
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
	return length;
}

// convert an array to a linked list
template<class T>
ll_node<T> *create_list_from_array(int length, T arr[]){
	if(length == 0) return NULL;
	ll_node<T> *head = create_node(arr[0]);
	ll_node<T> *temp = head;

	for(int i=1;i<length;i++){
		temp->next = create_node(arr[i]);
		temp = temp->next;
	}

	return head;
}

// push at the starting of a linked list
template<class T>
void push(ll_node<T> **head_ref, T data){
	ll_node<T> *new_node = create_node(data);
	new_node->data = data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

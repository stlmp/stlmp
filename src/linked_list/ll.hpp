#include <bits/stdc++.h>
using namespace std;

struct ll_node{
	int data;
	ll_node *next;
};

ll_node *create_node(int new_data){
	ll_node *new_node = NULL;
	new_node = new ll_node;
	new_node->data = new_data;
	new_node->next = NULL;
	return new_node;
}

void print_list(struct ll_node *head){
	while(head){
		cout << head->data << endl;
		head = head->next;
	}
}

int get_length(struct ll_node *head){
	int length = 0;
	while(head){
		length++;
		cout << head->data << " ";
		head = head->next;
	}
	return length;
}
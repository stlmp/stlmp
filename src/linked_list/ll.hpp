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
	new_node->next = *head_ref;
	*head_ref = new_node;
}

// insert a node after given node
template<class T>
void insert_after(ll_node<T> *prev_node, T data){
	if (prev_node == NULL) return;
	ll_node<T> *new_node = create_node(data);
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

// given a reference pointer to the head, appends a new node at the end.
template<class T>
void append(ll_node<T> **head_ref, T data){
	ll_node<T> *new_node = create_node(data);
	if(*head_ref == NULL){
		*head_ref = new_node;
		return;
	} 
	ll_node<T> *last_node = *head_ref;
	while(last_node->next) last_node = last_node->next;
	last_node->next = new_node;
}

// delete the node which contains the given data
template<class T>
void delete_node_with_data(ll_node<T> **head_ref, int data){
	if(*head_ref == NULL) return;
	ll_node<T> *temp_node = *head_ref, *prev_node;

	if(temp_node->data == data){
		*head_ref = temp_node->next;
		delete temp_node;
		return;
	}

	while(temp_node!=NULL && temp_node->data!=data){
		prev_node = temp_node;
		temp_node = temp_node->next;
	}
	prev_node->next = temp_node->next;
	delete temp_node;
}

// get position of a key in linked list
template<class T>
int search_key(ll_node<T> *head, T key){
	int position = -1;
	while(head){
		position++;
		cout << "pos: " << position << " data: " << head->data << endl;
		if(head->data == key) return position;
		head = head->next;
	}
	return -1;
}

//reverse list
template<class T>
void reverse_list(ll_node<T> **head_ref){
	ll_node<T> *prev = NULL;
    ll_node<T> *current = *head_ref;
    ll_node<T> *next;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head_ref = prev;
}

// move to next node
template<class T>
void move_next(ll_node<T> **head_ref){
	ll_node<T> *temp = *head_ref;
	temp = temp->next;
	*head_ref = temp;
}

// iterates through 2 lists and checks if they are equal
template<class T>
bool compare_lists(ll_node<T> *head1, ll_node<T> *head2){
	ll_node<T> *temp1 = head1;
	ll_node<T> *temp2 = head2;

	while(temp1 && temp2){
		if(temp1->data == temp2->data){
			move_next(&temp1);
			move_next(&temp2);
		}else{
			return false;
		}
	}

	if(temp1==NULL && temp2==NULL){
		return true;
	}
	return false;
}
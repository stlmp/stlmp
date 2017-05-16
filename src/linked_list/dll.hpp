#include <bits/stdc++.h>
using namespace std;

template<class T>
struct dll_node{
	T data;
	dll_node *next;
	dll_node *prev;
};

// assign value to node and return
template<class T>
dll_node<T> *create_node(T new_data){
	dll_node<T> *new_node = NULL;
	new_node = new dll_node<T>;
	new_node->data = new_data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}

// print list
template<class T>
void print_list(struct dll_node<T> *head){
	while(head){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

// get length of list
template<class T>
int get_length(struct dll_node<T> *head){
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
dll_node<T> *create_list_from_array(int length, T arr[]){
	if(length == 0) return NULL;
	dll_node<T> *head = create_node(arr[0]);
	dll_node<T> *temp = head;

	for(int i=1;i<length;i++){
		temp->next = create_node(arr[i]);
		temp->next->prev = temp;
		temp = temp->next;
	}

	return head;
}

// push at the starting of a linked list
template<class T>
void push(dll_node<T> **head_ref, T data){
	dll_node<T> *new_node = create_node(data);
	new_node->next = *head_ref;
	*head_ref = new_node;
}

// insert a node after given node
template<class T>
void insert_after(dll_node<T> *prev_node, T data){
	if (prev_node == NULL) return;
	dll_node<T> *new_node = create_node(data);
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

// given a reference pointer to the head, appends a new node at the end.
template<class T>
void append(dll_node<T> **head_ref, T data){
	dll_node<T> *new_node = create_node(data);
	if(*head_ref == NULL){
		*head_ref = new_node;
		return;
	} 
	dll_node<T> *last_node = *head_ref;
	while(last_node->next) last_node = last_node->next;
	last_node->next = new_node;
}

// delete the node which contains the given data
template<class T>
void delete_node_with_data(dll_node<T> **head_ref, int data){
	if(*head_ref == NULL) return;
	dll_node<T> *temp_node = *head_ref, *prev_node;

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
int search_key(dll_node<T> *head, T key){
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
void reverse_list(dll_node<T> **head_ref){
	dll_node<T> *prev = NULL;
    dll_node<T> *current = *head_ref;
    dll_node<T> *next;

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
void move_next(dll_node<T> **head_ref){
	dll_node<T> *temp = *head_ref;
	temp = temp->next;
	*head_ref = temp;
}

// move to next node
template<class T>
void move_prev(dll_node<T> **head_ref){
	dll_node<T> *temp = *head_ref;
	temp = temp->prev;
	*head_ref = temp;
}

// iterates through 2 lists and checks if they are equal
template<class T>
bool compare_lists(dll_node<T> *head1, dll_node<T> *head2){
	dll_node<T> *temp1 = head1;
	dll_node<T> *temp2 = head2;

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


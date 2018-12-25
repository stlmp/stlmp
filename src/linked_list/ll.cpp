#include <cstdlib>
#include <iostream>
#include <stlmp.h>

#include "../../include/stlmp.h"

using namespace stlmp::LinkedList;

// print list
template<class T>
void stlmp::LinkedList::SinglyLinkedList<T>::printList(stlmp::LinkedList::LLNode<T> head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

template<class T>
int SinglyLinkedList<T>::getLength(LLNode<T> head) {
    int length = 0;
    std::cout << "List:\n";
    while (head) {
        length++;
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
    return length;
}

// convert an array to a linked list
template<class T>
LLNode<T> *stlmp::LinkedList::create_list_from_array(int length, T *arr) {
    if (length == 0) return NULL;
    LLNode<T> *head = create_node(arr[0]);
    LLNode<T> *temp = head;

    for (int i = 1; i < length; i++) {
        temp->next = create_node(arr[i]);
        temp = temp->next;
    }

    return head;
}

// push at the starting of a linked list
template<class T>
void stlmp::LinkedList::push(LLNode<T> **head_ref, T data) {
    LLNode<T> *new_node = create_node(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// insert a node after given node
template<class T>
void stlmp::LinkedList::insert_after(LLNode<T> *prev_node, T data) {
    if (prev_node == NULL) return;
    LLNode<T> *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// given a reference pointer to the head, appends a new node at the end.
template<class T>
void stlmp::LinkedList::append(LLNode<T> **head_ref, T data) {
    LLNode<T> *new_node = create_node(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    LLNode<T> *last_node = *head_ref;
    while (last_node->next) last_node = last_node->next;
    last_node->next = new_node;
}

// delete the node which contains the given data
template<class T>
void stlmp::LinkedList::delete_node_with_data(LLNode<T> **head_ref, int data) {
    if (*head_ref == NULL) return;
    LLNode<T> *temp_node = *head_ref, *prev_node;

    if (temp_node->data == data) {
        *head_ref = temp_node->next;
        delete temp_node;
        return;
    }

    while (temp_node != NULL && temp_node->data != data) {
        prev_node = temp_node;
        temp_node = temp_node->next;
    }
    prev_node->next = temp_node->next;
    delete temp_node;
}

// get position of a key in linked list
template<class T>
int stlmp::LinkedList::search_key(LLNode<T> *head, T key) {
    int position = -1;
    while (head) {
        position++;
        std::cout << "pos: " << position << " data: " << head->data << std::endl;
        if (head->data == key) return position;
        head = head->next;
    }
    return -1;
}

//reverse list
template<class T>
void stlmp::LinkedList::reverse_list(LLNode<T> **head_ref) {
    LLNode<T> *prev = NULL;
    LLNode<T> *current = *head_ref;
    LLNode<T> *next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head_ref = prev;
}

// move to next node
template<class T>
void stlmp::LinkedList::move_next(LLNode<T> **head_ref) {
    LLNode<T> *temp = *head_ref;
    temp = temp->next;
    *head_ref = temp;
}

// iterates through 2 lists and checks if they are equal
template<class T>
bool stlmp::LinkedList::compare_lists(LLNode<T> *head1, LLNode<T> *head2) {
    LLNode<T> *temp1 = head1;
    LLNode<T> *temp2 = head2;

    while (temp1 && temp2) {
        if (temp1->data == temp2->data) {
            move_next(&temp1);
            move_next(&temp2);
        } else {
            return false;
        }
    }

    return temp1 == NULL && temp2 == NULL;
}

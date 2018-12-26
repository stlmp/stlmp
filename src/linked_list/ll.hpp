#include <cstdlib>
#include <iostream>
#include <stlmp.h>

using namespace stlmp::LinkedList;

// print list
template<class T>
void SinglyLinkedList<T>::printList() {
    auto *temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

template<class T>
int SinglyLinkedList<T>::getLength() {
    int length = 0;
    auto *temp = head;
    std::cout << "List:\n";
    while (temp) {
        length++;
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
    return length;
}

// convert an array to a linked list
template<class T>
SinglyLinkedList<T> *stlmp::LinkedList::create_list_from_array(int length, T *arr) {
    if (length == 0) return NULL;
    auto list = new SinglyLinkedList<T>(arr[0]);
    LLNode<T> *temp = list->getHead();

    for (int i = 1; i < length; i++) {
        temp->next = new LLNode<T>(arr[i]);
        temp = temp->next;
    }

    return list;
}

// push at the starting of a linked list
template<class T>
void SinglyLinkedList<T>::push(T data) {
    auto head_ref = &head;
    auto *new_node = new LLNode<T>(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// insert a node after given node
template<class T>
void SinglyLinkedList<T>::insertAfter(LLNode<T> *prev_node, T data) {
    if (prev_node == NULL) return;
    auto *new_node = new LLNode<T>(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// given a reference pointer to the head, appends a new node at the end.
template<class T>
void SinglyLinkedList<T>::append(T data) {
    auto *new_node = new LLNode<T>(data);
    auto head_ref = &head;
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
void SinglyLinkedList<T>::deleteNodeWithData(T data) {
    auto head_ref = &head;
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
int SinglyLinkedList<T>::searchKey(T key) {
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
void SinglyLinkedList<T>::reverseList() {
    auto head_ref = &head;
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
void SinglyLinkedList<T>::move_next(LLNode<T> **head_ref) {
    LLNode<T> *temp = *head_ref;
    temp = temp->next;
    *head_ref = temp;
}

// iterates through 2 lists and checks if they are equal
template<class T>
bool SinglyLinkedList<T>::compareTo(stlmp::LinkedList::SinglyLinkedList<T> *anotherList) {
    LLNode<T> *temp1 = head;
    LLNode<T> *temp2 = anotherList->getHead();

    while (temp1 && temp2) {
        if (temp1->data == temp2->data) {
            SinglyLinkedList<T>::move_next(&temp1);
            SinglyLinkedList<T>::move_next(&temp2);
        } else {
            return false;
        }
    }

    return temp1 == NULL && temp2 == NULL;
}

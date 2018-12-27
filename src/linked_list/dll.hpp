#include "stlmp.h"

using namespace stlmp::LinkedList;
using namespace std;

// print list
template<class T>
void DoublyLinkedList<T>::printList() {
    auto *temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// get length of list
template<class T>
int DoublyLinkedList<T>::getLength() {
    int length = 0;
    cout << "List:\n";
    auto *temp = head;
    while (temp) {
        length++;
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return length;
}

// convert an array to a linked list
template<class T>
DoublyLinkedList<T> *stlmp::LinkedList::create_doubly_linked_list_from_array(int length, T arr[]) {
    if (length == 0) return new DoublyLinkedList<T>(NULL);
    auto newList = new DoublyLinkedList<T>(arr[0]);
    auto *head = newList->getHead();
    auto *temp = head;

    for (int i = 1; i < length; i++) {
        temp->next = new DLLNode<T>(arr[i]);
        temp->next->prev = temp;
        temp = temp->next;
    }

    return newList;
}

// push at the starting of a linked list
template<class T>
void DoublyLinkedList<T>::push(T data) {
    auto head_ref = &head;
    auto *new_node = new DLLNode<T>(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// insert a node after given node
template<class T>
void DoublyLinkedList<T>::insertAfter(DLLNode<T> *prev_node, T data) {
    if (prev_node == NULL) return;
    auto *new_node = new DLLNode<T>(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// given a reference pointer to the head, appends a new node at the end.
template<class T>
void DoublyLinkedList<T>::append(T data) {
    auto head_ref = &head;
    auto *new_node = new DLLNode<T>(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    DLLNode<T> *last_node = *head_ref;
    while (last_node->next) last_node = last_node->next;
    last_node->next = new_node;
}

// delete the node which contains the given data
template<class T>
void DoublyLinkedList<T>::deleteNodeWithData(T data) {
    auto head_ref = &head;
    if (*head_ref == NULL) return;
    DLLNode<T> *temp_node = *head_ref, *prev_node;

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
int DoublyLinkedList<T>::searchKey(T key) {
    int position = -1;
    while (head) {
        position++;
        cout << "pos: " << position << " data: " << head->data << endl;
        if (head->data == key) return position;
        head = head->next;
    }
    return -1;
}

//reverse list
template<class T>
void DoublyLinkedList<T>::reverseList() {
    auto head_ref = &head;
    DLLNode<T> *prev = NULL;
    DLLNode<T> *current = *head_ref;
    DLLNode<T> *next;

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
void DoublyLinkedList<T>::move_next(DLLNode<T> **head_ref) {
    DLLNode<T> *temp = *head_ref;
    temp = temp->next;
    *head_ref = temp;
}

// move to next node
template<class T>
void DoublyLinkedList<T>::move_prev(DLLNode<T> **head_ref) {
    DLLNode<T> *temp = *head_ref;
    temp = temp->prev;
    *head_ref = temp;
}

// iterates through 2 lists and checks if they are equal
template<class T>
bool DoublyLinkedList<T>::compareTo(DoublyLinkedList<T> *anotherList) {
    DLLNode<T> *temp1 = this->getHead();
    DLLNode<T> *temp2 = anotherList->getHead();

    while (temp1 && temp2) {
        if (temp1->data == temp2->data) {
            move_next(&temp1);
            move_next(&temp2);
        } else {
            return false;
        }
    }

    if (temp1 == NULL && temp2 == NULL) {
        return true;
    }
    return false;
}


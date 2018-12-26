#include <iostream>
#include <cassert>
#include "stlmp.h"

using namespace stlmp::LinkedList;
using namespace std;

int main() {
    cout << "----------------------------------------------------" << endl;
    cout << "Simple list creation:" << endl;
    cout << "----------------------------------------------------" << endl;
    auto *linkedList = new SinglyLinkedList<int>(1);
    linkedList->append(2);
    cout << "Printing list:" << endl;
    linkedList->printList();

    cout << "Checking list length: " << linkedList->getLength() << endl;
    assert(linkedList->getLength() == 2);
    cout << "----------------------------------------------------" << endl;

    // create list from array
    cout << "create list from array" << endl;
    cout << "----------------------------------------------------" << endl;
    int foo[] = {1, 2, 3, 4, 5};
    SinglyLinkedList<int> *linkedList1 = create_list_from_array(sizeof(foo) / sizeof(foo[0]), foo);
    assert(linkedList1->getLength() ==
           sizeof(foo) / sizeof(foo[0])); // "create_list_from_array doesn't seem to work as expected!";
    cout << "----------------------------------------------------" << endl;

    // push
    cout << "push" << endl;
    cout << "----------------------------------------------------" << endl;
    int foo1[] = {1, 2, 3, 4, 5};
    SinglyLinkedList<int> *linkedList2 = create_list_from_array(sizeof(foo1) / sizeof(foo1[0]), foo1);
    linkedList2->push(6);
    assert(linkedList2->getLength() ==
           1 + sizeof(foo1) / sizeof(foo1[0]));//<< "push doesn't seem to work as expected!";
    cout << "----------------------------------------------------" << endl;

    // insert after
    cout << "insert after" << endl;
    cout << "----------------------------------------------------" << endl;
    int foo2[] = {1, 2, 3, 4, 5};
    SinglyLinkedList<int> *linkedList3 = create_list_from_array(sizeof(foo2) / sizeof(foo2[0]), foo2);
    linkedList3->insertAfter(linkedList3->getHead()->next, 6);
    assert(linkedList3->getLength() ==
           1 + sizeof(foo2) / sizeof(foo2[0]));//<< "insert_after doesn't seem to work as expected!";
    cout << "----------------------------------------------------" << endl;

    // append
    cout << "append" << endl;
    cout << "----------------------------------------------------" << endl;
    int foo3[] = {1, 2, 3, 4, 5};
    SinglyLinkedList<int> *linkedList4 = create_list_from_array(sizeof(foo3) / sizeof(foo3[0]), foo3);
    linkedList4->append(6);
    assert(linkedList4->getLength() == 1 + sizeof(foo3) / sizeof(foo3[0]));//<< "append doesn't seem to work as expected!";
    cout << "----------------------------------------------------" << endl;

    // append to null list
    cout << "append to null" << endl;
    cout << "----------------------------------------------------" << endl;
    int foo4[] = {};
    SinglyLinkedList<int> *linkedList5 = create_list_from_array(sizeof(foo4) / sizeof(foo4[0]), foo4);
    linkedList5->append(6);
    linkedList5->printList();
    assert(linkedList5->getLength() == 1 + sizeof(foo4) / sizeof(foo4[0]));
    //<< "append to null doesn't seem to work as expected!";
    cout << "----------------------------------------------------" << endl;

    // delete node
    cout << "delete node" << endl;
    cout << "----------------------------------------------------" << endl;
    // normal
    cout << "normal" << endl;
    int foo5[] = {1, 2, 3};
    SinglyLinkedList<int> *linkedList6 = create_list_from_array(sizeof(foo5) / sizeof(foo5[0]), foo5);
    linkedList6->deleteNodeWithData(2);
    assert(linkedList6->getLength() == -1 + sizeof(foo5) / sizeof(foo5[0]));
    //<< "delete_node_with_data doesn't seem to work as expected!";

    // empty list
    cout << "empty list" << endl;
    int foo52[] = {};
    SinglyLinkedList<int> *linkedList7 = create_list_from_array(sizeof(foo52) / sizeof(foo52[0]), foo52);
    linkedList7->deleteNodeWithData(2);
    assert(linkedList7->getLength() == 0);// << "delete_node_with_data doesn't seem to work as expected!";

    cout << "normal" << endl;
    int foo53[] = {1, 2, 3};
    SinglyLinkedList<int> *linkedList8 = create_list_from_array(sizeof(foo53) / sizeof(foo53[0]), foo53);
    linkedList8->deleteNodeWithData(1);
    assert(linkedList8->getLength() == -1 + sizeof(foo53) / sizeof(foo53[0]));
    //<< "delete_node_with_data doesn't seem to work as expected!";
    cout << "----------------------------------------------------" << endl;

    // search key
    cout << "search key" << endl;
    cout << "----------------------------------------------------" << endl;
    int foo6[] = {1, 2, 3};
    SinglyLinkedList<int> *linkedList9 = create_list_from_array(sizeof(foo6) / sizeof(foo6[0]), foo6);
    // not found should return -1
    assert(linkedList9->searchKey(4) == -1);// << "search_key doesn't seem to work as expected!";
    // 1 is at  index 0
    assert(linkedList9->searchKey(1) == 0);// << "search_key doesn't seem to work as expected!";
    cout << "----------------------------------------------------" << endl;

    // reverse list
    cout << "reverse list" << endl;
    cout << "----------------------------------------------------" << endl;
    int foo7[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    SinglyLinkedList<int> *linkedList10 = create_list_from_array(sizeof(foo7) / sizeof(foo7[0]), foo7);
    linkedList10->reverseList();
    assert(linkedList10->getHead()->data == 9);// << "reverse_list doesn't seem to work as expected!";
    cout << "----------------------------------------------------" << endl;

    //compare lists
    cout << "compare lists" << endl;
    cout << "----------------------------------------------------" << endl;
    int foo8[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    SinglyLinkedList<int> *head81 = create_list_from_array(sizeof(foo8) / sizeof(foo8[0]), foo8);
    SinglyLinkedList<int> *head82 = create_list_from_array(sizeof(foo8) / sizeof(foo8[0]), foo8);
    assert(head81->compareTo(head82));// << "compare_lists doesn't seem to work as expected!";
    cout << "----------------------------------------------------" << endl;

    cout << "compare unequal lists" << endl;
    cout << "----------------------------------------------------" << endl;
    int foo81[] = {1, 2, 3, 4, 5, 6, 8, 9};
    SinglyLinkedList<int> *head83 = create_list_from_array(sizeof(foo81) / sizeof(foo81[0]), foo81);
    assert(!head81->compareTo(head83));// << "compare_lists doesn't seem to work as expected!";
    cout << "----------------------------------------------------" << endl;
}

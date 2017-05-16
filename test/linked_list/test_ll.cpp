#include "gtest/gtest.h"
#include "ll.hpp"
#include <bits/stdc++.h>
using namespace std;

TEST(singly_linked_list, basic_creation){
	ll_node<int> *head = create_node(1);
	head->next = create_node(2);
	cout << "starting to print list" << endl;
	print_list(head);
	cout << "stopping to print list" << endl;

	cout << "Checking the length of the list" << endl;
	ASSERT_EQ(get_length(head), 2);
}

TEST(singly_linked_list, create_list_from_array){
	int foo[] = {1, 2, 3, 4, 5};
	ll_node<int> *head = create_list_from_array(sizeof(foo)/sizeof(foo[0]), foo);
	ASSERT_EQ(get_length(head), sizeof(foo)/sizeof(foo[0]));
}

TEST(singly_linked_list, push){
	int foo[] = {1, 2, 3, 4, 5};
	ll_node<int> *head = create_list_from_array(sizeof(foo)/sizeof(foo[0]), foo);
	push(&head, 6);
	ASSERT_EQ(get_length(head), 1 + sizeof(foo)/sizeof(foo[0]));
}

TEST(singly_linked_list, insert_after){
	int foo[] = {1, 2, 3, 4, 5};
	ll_node<int> *head = create_list_from_array(sizeof(foo)/sizeof(foo[0]), foo);
	insert_after(head, 6);
	ASSERT_EQ(get_length(head), 1 + sizeof(foo)/sizeof(foo[0]));
}

TEST(singly_linked_list, append){
	int foo[] = {1, 2, 3, 4, 5};
	ll_node<int> *head = create_list_from_array(sizeof(foo)/sizeof(foo[0]), foo);
	append(&head, 6);
	ASSERT_EQ(get_length(head), 1 + sizeof(foo)/sizeof(foo[0]));
}

TEST(singly_linked_list, append_to_null){
	int foo[] = {};
	ll_node<int> *head = create_list_from_array(sizeof(foo)/sizeof(foo[0]), foo);
	append(&head, 6);
	ASSERT_EQ(get_length(head), 1 + sizeof(foo)/sizeof(foo[0]));
}

TEST(singly_linked_list, delete_node_with_data_1){
	int foo[] = {1, 2, 3};
	ll_node<int> *head = create_list_from_array(sizeof(foo)/sizeof(foo[0]), foo);
	delete_node_with_data(&head, 2);
	ASSERT_EQ(get_length(head), -1 + sizeof(foo)/sizeof(foo[0]));
}

TEST(singly_linked_list, delete_node_with_data_2){
	int foo[] = {};
	ll_node<int> *head = create_list_from_array(sizeof(foo)/sizeof(foo[0]), foo);
	delete_node_with_data(&head, 2);
	ASSERT_EQ(get_length(head), 0);
}

TEST(singly_linked_list, delete_node_with_data_3){
	int foo[] = {1, 2, 3};
	ll_node<int> *head = create_list_from_array(sizeof(foo)/sizeof(foo[0]), foo);
	delete_node_with_data(&head, 1);
	ASSERT_EQ(get_length(head), -1 + sizeof(foo)/sizeof(foo[0]));
}

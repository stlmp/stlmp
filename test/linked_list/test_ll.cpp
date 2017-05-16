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
	ASSERT_EQ(get_length(head), 2) << "reverse_list doesn't seem to work as expected!";
}

TEST(singly_linked_list, create_list_from_array){
	int foo[] = {1, 2, 3, 4, 5};
	ll_node<int> *head = create_list_from_array(sizeof(foo)/sizeof(foo[0]), foo);
	ASSERT_EQ(get_length(head), sizeof(foo)/sizeof(foo[0])) << "reverse_list doesn't seem to work as expected!";
}

TEST(singly_linked_list, push){
	int foo[] = {1, 2, 3, 4, 5};
	ll_node<int> *head = create_list_from_array(sizeof(foo)/sizeof(foo[0]), foo);
	push(&head, 6);
	ASSERT_EQ(get_length(head), 1 + sizeof(foo)/sizeof(foo[0])) << "reverse_list doesn't seem to work as expected!";
}

TEST(singly_linked_list, insert_after){
	int foo[] = {1, 2, 3, 4, 5};
	ll_node<int> *head = create_list_from_array(sizeof(foo)/sizeof(foo[0]), foo);
	insert_after(head, 6);
	ASSERT_EQ(get_length(head), 1 + sizeof(foo)/sizeof(foo[0])) << "reverse_list doesn't seem to work as expected!";
}

TEST(singly_linked_list, append){
	int foo[] = {1, 2, 3, 4, 5};
	ll_node<int> *head = create_list_from_array(sizeof(foo)/sizeof(foo[0]), foo);
	append(&head, 6);
	ASSERT_EQ(get_length(head), 1 + sizeof(foo)/sizeof(foo[0])) << "reverse_list doesn't seem to work as expected!";
}

TEST(singly_linked_list, append_to_null){
	int foo[] = {};
	ll_node<int> *head = create_list_from_array(sizeof(foo)/sizeof(foo[0]), foo);
	append(&head, 6);
	ASSERT_EQ(get_length(head), 1 + sizeof(foo)/sizeof(foo[0])) << "reverse_list doesn't seem to work as expected!";
}

TEST(singly_linked_list, delete_node_with_data){
	// normal
	int foo[] = {1, 2, 3};
	ll_node<int> *head = create_list_from_array(sizeof(foo)/sizeof(foo[0]), foo);
	delete_node_with_data(&head, 2);
	ASSERT_EQ(get_length(head), -1 + sizeof(foo)/sizeof(foo[0])) << "reverse_list doesn't seem to work as expected!";

	// empty list
	int foo2[] = {};
	ll_node<int> *head2 = create_list_from_array(sizeof(foo2)/sizeof(foo2[0]), foo2);
	delete_node_with_data(&head2, 2);
	ASSERT_EQ(get_length(head2), 0) << "reverse_list doesn't seem to work as expected!";

	int foo3[] = {1, 2, 3};
	ll_node<int> *head3 = create_list_from_array(sizeof(foo3)/sizeof(foo3[0]), foo3);
	delete_node_with_data(&head3, 1);
	ASSERT_EQ(get_length(head3), -1 + sizeof(foo3)/sizeof(foo3[0])) << "reverse_list doesn't seem to work as expected!";
}

TEST(singly_linked_list, search_key){
	int foo[] = {1, 2, 3};
	ll_node<int> *head = create_list_from_array(sizeof(foo)/sizeof(foo[0]), foo);
	// not found should return -1
	EXPECT_EQ(search_key(head, 4), -1) << "reverse_list doesn't seem to work as expected!";
	// 1 is at  index 0
	EXPECT_EQ(search_key(head, 1), 0) << "reverse_list doesn't seem to work as expected!";
}

TEST(singly_linked_list, reverse_list){
	int foo[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	ll_node<int> *head = create_list_from_array(sizeof(foo)/sizeof(foo[0]), foo);
	reverse_list(&head);
	EXPECT_EQ(head->data, 9) << "reverse_list doesn't seem to work as expected!";
}

TEST(singly_linked_list, compare_lists){
	int foo[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	ll_node<int> *head1 = create_list_from_array(sizeof(foo)/sizeof(foo[0]), foo);
	ll_node<int> *head2 = create_list_from_array(sizeof(foo)/sizeof(foo[0]), foo);
	EXPECT_EQ(compare_lists(head1, head2), true) << "reverse_list doesn't seem to work as expected!";
}

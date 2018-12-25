#include "gtest/gtest.h"
#include "ll.hpp"
#include <bits/stdc++.h>
using namespace std;

TEST(singly_linked_list, all_tests){
	// simple creation etc.
	cout << "----------------------------------------------------" << endl;
	cout << "Simple list creation:" << endl;
	cout << "----------------------------------------------------" << endl;
	ll_node<int> *head0 = create_node(1);
	head0->next = create_node(2);
	cout << "starting to print list" << endl;
	print_list(head0);
	cout << "stopping to print list" << endl;

	cout << "Checking the length of the list" << endl;
	ASSERT_EQ(get_length(head0), 2);
	cout << "----------------------------------------------------" << endl;

	// create list from array
	cout << "create list from array" << endl;
	cout << "----------------------------------------------------" << endl;
	int foo[] = {1, 2, 3, 4, 5};
	ll_node<int> *head = create_list_from_array(sizeof(foo)/sizeof(foo[0]), foo);
	ASSERT_EQ(get_length(head), sizeof(foo)/sizeof(foo[0])) << "create_list_from_array doesn't seem to work as expected!";
	cout << "----------------------------------------------------" << endl;

	// push
	cout << "push" << endl;
	cout << "----------------------------------------------------" << endl;
	int foo1[] = {1, 2, 3, 4, 5};
	ll_node<int> *head1 = create_list_from_array(sizeof(foo1)/sizeof(foo1[0]), foo1);
	push(&head1, 6);
	ASSERT_EQ(get_length(head1), 1 + sizeof(foo1)/sizeof(foo1[0])) << "push doesn't seem to work as expected!";
	cout << "----------------------------------------------------" << endl;

	// insert after
	cout << "insert after" << endl;
	cout << "----------------------------------------------------" << endl;
	int foo2[] = {1, 2, 3, 4, 5};
	ll_node<int> *head2 = create_list_from_array(sizeof(foo2)/sizeof(foo2[0]), foo2);
	insert_after(head2, 6);
	ASSERT_EQ(get_length(head2), 1 + sizeof(foo2)/sizeof(foo2[0])) << "insert_after doesn't seem to work as expected!";
	cout << "----------------------------------------------------" << endl;

	// append
	cout << "append" << endl;
	cout << "----------------------------------------------------" << endl;
	int foo3[] = {1, 2, 3, 4, 5};
	ll_node<int> *head3 = create_list_from_array(sizeof(foo3)/sizeof(foo3[0]), foo3);
	append(&head3, 6);
	ASSERT_EQ(get_length(head3), 1 + sizeof(foo3)/sizeof(foo3[0])) << "append doesn't seem to work as expected!";
	cout << "----------------------------------------------------" << endl;

	// append to null list
	cout << "append to null" << endl;
	cout << "----------------------------------------------------" << endl;
	int foo4[] = {};
	ll_node<int> *head4 = create_list_from_array(sizeof(foo4)/sizeof(foo4[0]), foo4);
	append(&head4, 6);
	ASSERT_EQ(get_length(head4), 1 + sizeof(foo4)/sizeof(foo4[0])) << "append tonull doesn't seem to work as expected!";
	cout << "----------------------------------------------------" << endl;

	// delete node
	cout << "delete node" << endl;
	cout << "----------------------------------------------------" << endl;
	// normal
	cout << "normal" << endl;
	int foo5[] = {1, 2, 3};
	ll_node<int> *head5 = create_list_from_array(sizeof(foo5)/sizeof(foo5[0]), foo5);
	delete_node_with_data(&head5, 2);
	ASSERT_EQ(get_length(head5), -1 + sizeof(foo5)/sizeof(foo5[0])) << "delete_node_with_data doesn't seem to work as expected!";

	// empty list
	cout << "empty list" << endl;
	int foo52[] = {};
	ll_node<int> *head52 = create_list_from_array(sizeof(foo52)/sizeof(foo52[0]), foo52);
	delete_node_with_data(&head52, 2);
	ASSERT_EQ(get_length(head52), 0) << "delete_node_with_data doesn't seem to work as expected!";

	cout << "normal" << endl;
	int foo53[] = {1, 2, 3};
	ll_node<int> *head53 = create_list_from_array(sizeof(foo53)/sizeof(foo53[0]), foo53);
	delete_node_with_data(&head53, 1);
	ASSERT_EQ(get_length(head53), -1 + sizeof(foo53)/sizeof(foo53[0])) << "delete_node_with_data doesn't seem to work as expected!";
	cout << "----------------------------------------------------" << endl;

	// search key
	cout << "search key" << endl;
	cout << "----------------------------------------------------" << endl;
	int foo6[] = {1, 2, 3};
	ll_node<int> *head6 = create_list_from_array(sizeof(foo6)/sizeof(foo6[0]), foo6);
	// not found should return -1
	EXPECT_EQ(search_key(head6, 4), -1) << "search_key doesn't seem to work as expected!";
	// 1 is at  index 0
	EXPECT_EQ(search_key(head6, 1), 0) << "search_key doesn't seem to work as expected!";
	cout << "----------------------------------------------------" << endl;

	// reverse list
	cout << "reverse list" << endl;
	cout << "----------------------------------------------------" << endl;
	int foo7[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	ll_node<int> *head7 = create_list_from_array(sizeof(foo7)/sizeof(foo7[0]), foo7);
	reverse_list(&head7);
	EXPECT_EQ(head7->data, 9) << "reverse_list doesn't seem to work as expected!";
	cout << "----------------------------------------------------" << endl;

	//compare lists
	cout << "compare lists" << endl;
	cout << "----------------------------------------------------" << endl;
	int foo8[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	ll_node<int> *head81 = create_list_from_array(sizeof(foo8)/sizeof(foo8[0]), foo8);
	ll_node<int> *head82 = create_list_from_array(sizeof(foo8)/sizeof(foo8[0]), foo8);
	EXPECT_EQ(compare_lists(head81, head82), true) << "compare_lists doesn't seem to work as expected!";
	cout << "----------------------------------------------------" << endl;
}

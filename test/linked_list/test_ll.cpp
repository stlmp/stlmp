#include "gtest/gtest.h"
#include "ll.hpp"
#include <bits/stdc++.h>
using namespace std;

TEST(stlmp, linked_list_simple){
	ll_node<int> *head = create_node(1);
	head->next = create_node(2);
	cout << "starting to print list" << endl;
	print_list(head);
	cout << "stopping to print list" << endl;

	cout << "Checking the length of the list" << endl;
	ASSERT_EQ(get_length(head), 2);
}

TEST(stlmp, linked_list_from_array){
	int foo[] = {1, 2, 3, 4, 5};
	ll_node<int> *head = create_list_from_array(sizeof(foo)/sizeof(foo[0]), foo);
	ASSERT_EQ(get_length(head), sizeof(foo)/sizeof(foo[0]));
}

TEST(stlmp, linked_list_push){
	int foo[] = {1, 2, 3, 4, 5};
	ll_node<int> *head = create_list_from_array(sizeof(foo)/sizeof(foo[0]), foo);
	push(&head, 6);
	ASSERT_EQ(get_length(head), 1 + sizeof(foo)/sizeof(foo[0]));
}
#include "gtest/gtest.h"
#include "ll.hpp"
#include <bits/stdc++.h>
using namespace std;

TEST(stlmp, linked_list){
	struct ll_node *head = create_node(1);
	head->next = create_node(2);
	cout << "starting to print list" << endl;
	print_list(head);
	cout << "stopping to print list" << endl;

	cout << "Checking the length of the list" << endl;
	ASSERT_EQ(get_length(head), 2);
}
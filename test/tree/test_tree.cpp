#include "gtest/gtest.h"
#include "tree.hpp"
#include <bits/stdc++.h>
using namespace std;

TEST(simple_tree, all_tests){
	tree_node<int> *top = NULL;
	ASSERT_EQ(get_length(top), 0);

	top = new tree_node<int>(1);
	ASSERT_EQ(get_length(top), 1);

	top->left_child = new tree_node<int>(1);
	top->right_child = new tree_node<int>(2);
	top->left_child->right_child = new tree_node<int>(3);
	top->left_child->left_child = new tree_node<int>(4);
	ASSERT_EQ(get_length(top), 3);
}
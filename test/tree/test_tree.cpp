#include "gtest/gtest.h"
#include "tree.hpp"
#include "bst.hpp"
#include "segment_tree.hpp"
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

TEST(binary_search_tree, all_tests){
	BST<int> *bst = new BST<int>();
	EXPECT_EQ(bst->get_length(), 0);
	EXPECT_EQ(bst->get_max(), '\0');
	EXPECT_EQ(bst->get_min(), '\0');

	bst->insert(5);
	bst->insert(1);
	EXPECT_EQ(bst->get_length(), 2);
	EXPECT_EQ(bst->get_max(), 5);
	EXPECT_EQ(bst->get_min(), 1);
	EXPECT_EQ(bst->count_nodes(), 2);
	EXPECT_FALSE(bst->find(23));
	EXPECT_TRUE(bst->find(1));
	bst->print();
	bst->print_max_path();

	bst->insert(2);
	bst->insert(3);
	bst->insert(4);
	bst->insert(10);
	EXPECT_EQ(bst->get_length(), 5);
	EXPECT_EQ(bst->get_max(), 10);
	EXPECT_EQ(bst->get_min(), 1);
	EXPECT_EQ(bst->count_nodes(), 6);
	EXPECT_FALSE(bst->find(23));
	EXPECT_TRUE(bst->find(10));
	bst->print();
	bst->print_max_path();
	bst->print_post_order();
	bst->print_pre_order();
	bst->print_max_path();

	bst->insert(6);
	bst->insert(8);
	EXPECT_EQ(bst->get_length(), 5);
	EXPECT_EQ(bst->get_max(), 10);
	EXPECT_EQ(bst->get_min(), 1);
	EXPECT_EQ(bst->count_nodes(), 8);
	EXPECT_FALSE(bst->find(233));
	EXPECT_TRUE(bst->find(1));
	bst->print();
	bst->level_order();
	bst->delete_value(10);
	cout << "After deletion of 10:" << endl;
	bst->print();
	EXPECT_EQ(bst->get_count(), 7);

	BST<int> *bst2 = new BST<int>(1);
	EXPECT_EQ(bst2->get_length(), 1);
	bst2->print();
	bst2->print_max_path();

	bst2->insert(5);
	bst2->insert(2);
	EXPECT_EQ(bst2->get_length(), 3);
	bst2->print();
	bst2->print_max_path();
}

TEST(segment_tree, all_tests){
	int ar[] = {1, 2, 3, 4, 5};
	segment_tree *st = new segment_tree(ar, 5);
	st->print();
	st->update(0, 0);
	st->update(2, 4);
	st->print();
	ASSERT_EQ(st->get(0), 15);
	ASSERT_EQ(st->get_sum(0, 4), 15);
}


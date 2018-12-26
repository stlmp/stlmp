//
// Created by manparvesh on 12/26/18.
//
#include "stlmp.h"
using namespace stlmp::Tree;

int main() {
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


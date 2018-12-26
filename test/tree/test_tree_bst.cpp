//
// Created by manparvesh on 12/26/18.
//
#include <cassert>
#include "stlmp.h"

using namespace stlmp::Tree::BST;

int main() {
    auto *bst = new stlmp::Tree::BST::BST<int>();
    assert(bst->get_length() == 0);
    assert(bst->get_max() == '\0');
    assert(bst->get_min() == '\0');

    bst->insert(5);
    bst->insert(1);
    assert(bst->get_length() == 2);
    assert(bst->get_max() == 5);
    assert(bst->get_min() == 1);
    assert(bst->count_nodes() == 2);
    assert(!bst->find(23));
    assert(bst->find(1));
    bst->print();
    bst->print_max_path();

    bst->insert(2);
    bst->insert(3);
    bst->insert(4);
    bst->insert(10);
    assert(bst->get_length() == 5);
    assert(bst->get_max() == 10);
    assert(bst->get_min() == 1);
    assert(bst->count_nodes() == 6);
    assert(!bst->find(23));
    assert(bst->find(10));
    bst->print();
    bst->print_max_path();
    bst->print_post_order();
    bst->print_pre_order();
    bst->print_max_path();

    bst->insert(6);
    bst->insert(8);
    assert(bst->get_length() == 5);
    assert(bst->get_max() == 10);
    assert(bst->get_min() == 1);
    assert(bst->count_nodes() == 8);
    assert(!bst->find(233));
    assert(bst->find(1));
    bst->print();
    bst->level_order();
    bst->delete_value(10);
    cout << "After deletion of 10:" << endl;
    bst->print();
    assert(bst->get_count() == 7);

    auto *bst2 = new stlmp::Tree::BST::BST<int>(1);
    assert(bst2->get_length() == 1);
    bst2->print();
    bst2->print_max_path();

    bst2->insert(5);
    bst2->insert(2);
    assert(bst2->get_length() == 3);
    bst2->print();
    bst2->print_max_path();
}


#include "stlmp.h"

using namespace stlmp::Tree;

template<class T>
void TreeNode<T>::insertRight(T new_data) {
    auto *new_node = new TreeNode<T>(new_data);
    this->right_child = new_node;
}

template<class T>
void TreeNode<T>::insertLeft(T new_data) {
    auto *new_node = new TreeNode<T>(new_data);
    this->left_child = new_node;
}

template<class T>
int stlmp::Tree::get_length(TreeNode<T> *top) {
    if (top == NULL) return 0;
    return 1 + max(get_length(top->left_child), get_length(top->right_child));
}

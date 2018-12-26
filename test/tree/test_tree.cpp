#include <cassert>
#include "stlmp.h"
using namespace stlmp::Tree;

int main() {
    TreeNode<int> *top = NULL;
    assert(get_length(top) == 0);

    top = new TreeNode<int>(1);
    assert(get_length(top) == 1);

    top->left_child = new TreeNode<int>(1);
    top->right_child = new TreeNode<int>(2);
    top->left_child->right_child = new TreeNode<int>(3);
    top->left_child->left_child = new TreeNode<int>(4);
    assert(get_length(top) == 3);
}

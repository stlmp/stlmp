#include "stlmp.h"

using namespace stlmp::Tree::BST;

template<class T>
int stlmp::Tree::BST::BST<T>::_get_length(BSTNode<T> *node) {
    if (node == NULL) return 0;
    return 1 + max(_get_length(node->left_child), _get_length(node->right_child));
}

template<class T>
void stlmp::Tree::BST::BST<T>::level_order() {
    _level_order(this->node);
}

template<class T>
int stlmp::Tree::BST::BST<T>::get_count() {
    return _get_count(this->node);
}

template<class T>
void stlmp::Tree::BST::BST<T>::delete_value(T del_data) {
    this->node = _delete_value(this->node, del_data);
}

template<class T>
void stlmp::Tree::BST::BST<T>::print_max_path() {
    cout << "Max path:" << endl;
    _print_max_path(node);
    cout << endl;
}

template<class T>
bool stlmp::Tree::BST::BST<T>::find(T data) {
    return _find(node, data);
}

template<class T>
int stlmp::Tree::BST::BST<T>::count_nodes() {
    return _count_nodes(node);
}

template<class T>
T stlmp::Tree::BST::BST<T>::get_min() {
    return _get_min(node);
}

template<class T>
T stlmp::Tree::BST::BST<T>::get_max() {
    return _get_max(node);
}

template<class T>
void stlmp::Tree::BST::BST<T>::print_pre_order() {
    cout << "Printing BST (pre order):" << endl;
    _print_pre_order(node);
    cout << endl;
}

template<class T>
void stlmp::Tree::BST::BST<T>::print_post_order() {
    cout << "Printing BST (post order):" << endl;
    _print_post_order(node);
    cout << endl;
}

template<class T>
void stlmp::Tree::BST::BST<T>::print() {
    cout << "Printing BST (in order):" << endl;
    _print(node);
    cout << endl;
}

template<class T>
int stlmp::Tree::BST::BST<T>::get_length() {
    return _get_length(node);
}

template<class T>
void stlmp::Tree::BST::BST<T>::insert(T new_data) {
    auto *new_node = new BSTNode<T>(new_data);
    if (node == NULL) {
        node = new BSTNode<T>(new_data);
        return;
    }
    _insert(node, new_data);
}

template<class T>
T stlmp::Tree::BST::BST<T>::data() {
    return this->node->data;
}

template<class T>
void stlmp::Tree::BST::BST<T>::_level_order(BSTNode<T> *node) {
    if (node == NULL) return;
    cout << "Level order traversal:" << endl;
    auto *q = new Queue::Queue<BSTNode<T> *>();
    q->push(node);
    while (q->size) {
        BSTNode<T> *temp = q->pop();
        if (temp->left_child) q->push(temp->left_child);
        if (temp->right_child) q->push(temp->right_child);
        cout << temp->data << " ";
    }
    cout << endl;
    delete q;
}

template<class T>
int stlmp::Tree::BST::BST<T>::_get_count(BSTNode<T> *node) {
    if (node == NULL) return 0;
    return 1 + _get_count(node->left_child) + _get_count(node->right_child);
}

template<class T>
BSTNode<T> *stlmp::Tree::BST::BST<T>::_delete_value(BSTNode<T> *root, T del_data) {
    if (root == NULL) return root;

    if (del_data < root->data) {
        root->left_child = _delete_value(root->left_child, del_data);
    } else if (del_data > root->data) {
        root->right_child = _delete_value(root->right_child, del_data);
    } else {
        // check if one child is NULL
        if (root->left_child == NULL) {
            BSTNode<T> *temp_node = root->right_child;
            delete root;
            return temp_node;
        } else if (root->right_child == NULL) {
            BSTNode<T> *temp_node = root->left_child;
            delete root;
            return temp_node;
        }

        // if the node has both the
        BSTNode<T> *temp_node = _get_min_node(root->right_child);
        cout << "min node " << temp_node->data << endl;
        root->data = temp_node->data;
        root->right_child = _delete_value(root->right_child, temp_node->data);
    }
    return root;
}

template<class T>
BSTNode<T> *stlmp::Tree::BST::BST<T>::_get_min_node(BSTNode<T> *node) {
    if (node == NULL) return NULL;
    BSTNode<T> *temp_node = node;
    while (temp_node->left_child) {
        temp_node = temp_node->left_child;
    }
    return temp_node;
}

template<class T>
T stlmp::Tree::BST::BST<T>::_get_min(BSTNode<T> *node) {
    if (node == NULL) return '\0';
    BSTNode<T> *temp_node = node;
    while (temp_node->left_child) {
        temp_node = temp_node->left_child;
    }
    return temp_node->data;
}

template<class T>
T stlmp::Tree::BST::BST<T>::_get_max(BSTNode<T> *node) {
    if (node == NULL) return '\0';
    BSTNode<T> *temp_node = node;
    while (temp_node->right_child) {
        temp_node = temp_node->right_child;
    }
    return temp_node->data;
}

template<class T>
void stlmp::Tree::BST::BST<T>::_print_max_path(BSTNode<T> *node) {
    if (!node) return;
    cout << node->data << ' ';
    if (_get_length(node->left_child)) {
        _print_max_path(node->left_child);
    } else {
        _print_max_path(node->right_child);
    }
}

template<class T>
bool stlmp::Tree::BST::BST<T>::_find(BSTNode<T> *node, T data) {
    if (node) {
        if (node->data == data) {
            return true;
        }
        if (node->data > data) {
            // go left
            return _find(node->left_child, data);
        } else {
            return _find(node->right_child, data);
        }
    }
    return false;
}

template<class T>
int stlmp::Tree::BST::BST<T>::_count_nodes(BSTNode<T> *node) {
    if (!node) return 0;
    return 1 + _count_nodes(node->left_child) + _count_nodes(node->right_child);
}

template<class T>
void stlmp::Tree::BST::BST<T>::_print_pre_order(BSTNode<T> *node) {
    if (!node) return;
    cout << node->data << " ";
    _print_pre_order(node->left_child);
    _print_pre_order(node->right_child);
}

template<class T>
void stlmp::Tree::BST::BST<T>::_print_post_order(BSTNode<T> *node) {
    if (!node) return;
    _print_post_order(node->left_child);
    _print_post_order(node->right_child);
    cout << node->data << " ";
}

template<class T>
void stlmp::Tree::BST::BST<T>::_print(BSTNode<T> *node) {
    if (!node) return;
    _print(node->left_child);
    cout << node->data << " ";
    _print(node->right_child);
}

template<class T>
void stlmp::Tree::BST::BST<T>::_insert(BSTNode<T> *node, T new_data) {
    // if node exists
    if (node->data > new_data) {
        // go left
        if (node->left_child) {
            _insert(node->left_child, new_data);
        } else {
            node->left_child = new BSTNode<T>(new_data);
        }
    } else {
        // right
        if (node->right_child) {
            _insert(node->right_child, new_data);
        } else {
            node->right_child = new BSTNode<T>(new_data);
        }
    }
}

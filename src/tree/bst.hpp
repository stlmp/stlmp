#include <bits/stdc++.h>
using namespace std;

template<class T>
struct bst_node{
	T data;
	bst_node *left_child;
	bst_node *right_child;

	bst_node(T new_data) : data(new_data), left_child(NULL), right_child(NULL) {};
};

template<class T>
class BST{
private:
	bst_node<T> *node;

	// helper functions 
	int _get_length(bst_node<T> *node){
		if(node == NULL) return 0;
		return 1 + max(_get_length(node->left_child), _get_length(node->right_child));
	}

	void _insert(bst_node<T> *node, T new_data){
		// if node exists
		if(node->data > new_data){
			// go left
			if(node->left_child){
				_insert(node->left_child, new_data);
			}else{
				node->left_child = new bst_node<T>(new_data);
			}
		}else{
			// right
			if(node->right_child){
				_insert(node->right_child, new_data);
			}else{
				node->right_child = new bst_node<T>(new_data);
			}
		}
	}

	void _print(bst_node<T> *node){
		if(!node) return;
		_print(node->left_child);
		cout << node->data << " ";
		_print(node->right_child);
	}

	void _print_post_order(bst_node<T> *node){
		if(!node) return;
		_print_post_order(node->left_child);
		_print_post_order(node->right_child);
		cout << node->data << " ";
	}

	void _print_pre_order(bst_node<T> *node){
		if(!node) return;
		cout << node->data << " ";
		_print_pre_order(node->left_child);
		_print_pre_order(node->right_child);
	}

	int _count_nodes(bst_node<T> *node){
		if(!node) return 0;
		return 1 + _count_nodes(node->left_child) + _count_nodes(node->right_child);
	}

	bool _find(bst_node<T> *node, T data){
		if(node){
			if(node->data == data){
				return true;
			}
			return _find(node->left_child, data) || _find(node->right_child, data);
		}
		return false;
	}

	void _print_max_path(bst_node<T> *node){
		if(!node) return;
		cout << node->data << ' ';
		if(_get_length(node->left_child)){
			_print_max_path(node->left_child);
		}else{
			_print_max_path(node->right_child);
		}
	}

	bool _delete_value(bst_node<T> *parent, bst_node<T> *current, T del_data){
		if(!current) return false;
		if(current->data == del_data){
			if(current->left_child != NULL || current->right_child != NULL){
				// has one or none of the children
				bst_node<T> *temp_node = current->left_child;
				if(current->right_child) temp_node = current->right_child;
				if(parent){
					if(parent->left_child == current){
						parent->left_child = temp_node;
					}else{
						parent->right_child = temp_node;
					}
				}else{
					this->node = temp_node;
				}
			}else{
				// has both the children
				bst_node<T> *valid_substitute = current->right_child;
				while(valid_substitute->left_child) valid_substitute = valid_substitute->left_child;
				T temp_data = current->data;
				current->data = valid_substitute->data; 
				valid_substitute->data = temp_data;
				// recursively rearrange the nodes
				return _delete_value(current, current->right_child, temp_data);
			}
			delete current;
			return true;
		}
		return _delete_value(current, current->left_child, del_data) || 
				_delete_value(current, current->right_child, del_data);
	}
public:
	BST() : node(NULL) {}
	BST(T new_data) : node(new bst_node<T>(new_data)) {}
	~BST();

	void insert(T new_data){
		bst_node<T> *new_node = new bst_node<T>(new_data);
		if(node == NULL){
			node = new bst_node<T>(new_data);
			return;
		}
		_insert(node, new_data);
	}

	int get_length(){
		return _get_length(node);
	}

	void print(){
		cout << "Printing BST (in order):" << endl;
		_print(node);
		cout << endl;
	}

	void print_post_order(){
		cout << "Printing BST (post order):" << endl;
		_print_post_order(node);
		cout << endl;
	}

	void print_pre_order(){
		cout << "Printing BST (pre order):" << endl;
		_print_pre_order(node);
		cout << endl;
	}

	T get_max(){
		if(node == NULL) return '\0';
		bst_node<T> *temp_node = node;
		while(temp_node->right_child){
			temp_node = temp_node->right_child;
		}
		return temp_node->data;
	}

	T get_min(){
		if(node == NULL) return '\0';
		bst_node<T> *temp_node = node;
		while(temp_node->left_child){
			temp_node = temp_node->left_child;
		}
		return temp_node->data;
	}

	int count_nodes(){
		return _count_nodes(node);
	}

	bool find(T data){
		return _find(node, data);
	}

	void print_max_path(){
		cout << "Max path:" << endl;
		_print_max_path(node);
		cout << endl;
	}

	bool delete_value(T del_data){
		return _delete_value(NULL, this->node, del_data);
	}
};

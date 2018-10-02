#include <iostream>

using namespace std;

class node{
	public:
		int key;
		node *parent, *left, *right;
		char color;
		
		node(){
		}
		
		node(int del){
			key=del;
		}
		
		node(int x, node* s){
			key=x;
			parent=left=right=s;
			color='r';
		}
};

class rbtree{
	public:
		node *root, sentinal;
		
		rbtree(){
			sentinal.key=-1;
			sentinal.left=sentinal.right=sentinal.parent=NULL;
			sentinal.color='b';
			root=&sentinal;
		}
		
		void rb_delete();
		void deleteFix(node *);
		void transplant(node *, node *);
		node* tree_minimum(node *);
		void insert();
		void insertFix(node *);
		void leftRotate(node*);
		void rightRotate(node*);
		void disp();
		void display(node *);
		node* search();
};

node* rbtree::search(){
	int deleteValue;
	cout<<"\nEnter key of the node to be deleted : ";
	cin>>deleteValue;
	
	node *z=new node(deleteValue);
	node *p=root;
	
	while(p){
		if(z->key == p->key)	return p;
		else if(z->key < p->key)	p=p->left;
		else 	p=p->right;
	}
	
	cout<<"\nThe color of searched node : "<<p->color<<"\n";
	return p;
}

void rbtree::rb_delete(){
	node *z=search(), *x, *y;
	y=z;
	char y_original_color=y->color;
	
	if(z->left == &sentinal){
		x=z->right;
		transplant(z, z->right);
	}
	else if(z->right == &sentinal){
		x=z->left;
		transplant(z, z->left);
	}
	else{
		y=tree_minimum(z->right);
		y_original_color=y->color;
		x=y->right;
		
		if(y->parent == z){
			x->parent=y;
		}
		else{
			transplant(y, y->right);
			y->right=z->right;
			y->right->parent=y;
		}
		
		transplant(z, y);
		y->left=z->left;
		y->left->parent=y;
		y->color=z->color;
	}
	
	if(y_original_color == 'b'){
		deleteFix(x);
	}
}

node* rbtree::tree_minimum(node* x){
	while(x->left != &sentinal){
		x=x->left;
	}
	
	return x;
}

void rbtree::transplant(node* u, node* v){
	if(u->parent == &sentinal){
		root=v;
	}
	else if(u == u->parent->left){
		u->parent->left=v;
	}
	else{
		u->parent->right=v;
	}
	
	v->parent=u->parent;
}

void rbtree::deleteFix(node *x){
	node *w;
	while(x != root && x->color == 'b'){
		if(x == x->parent->left){
			w=x->parent->right;
			
			if(w->color == 'r'){
				w->color='b';
				x->parent->color='r';
				leftRotate(x->parent);
				w=x->parent->right;
			}
			
			if(w->left->color == 'b' && w->right->color == 'b'){
				w->color='r';
				x=x->parent;
			}
			else{
				if(w->right->color == 'b'){
					w->left->color='b';
					w->color='r';
					rightRotate(w);
					w=x->parent->right;
				}
				
				w->color=x->parent->color;
				x->parent->color='b';
				w->right->color='b';
				leftRotate(x->parent);
				x=root;
			}
		}
		else{
			w=x->parent->left;
			
			if(w->color == 'r'){
				w->color='b';
				x->parent->color='r';
				rightRotate(x->parent);
				w=x->parent->left;
			}
			
			if(w->left->color == 'b' && w->right->color == 'b'){
				w->color='r';
				x=x->parent;
			}
			else{
				if(w->left->color == 'b'){
					w->right->color='b';
					w->color='r';
					leftRotate(w);
					w=x->parent->left;
				}
				
				w->color=x->parent->color;
				x->parent->color='b';
				w->left->color='b';
				rightRotate(x->parent);
				x=root;
			}
		}
	}
	
	x->color='b';
}

void rbtree::leftRotate(node *x){
	node *y=x->right;
	x->right=y->left;
	
	if(y->left != &sentinal){
		y->left->parent=x;
	}
	
	y->parent=x->parent;
	
	if(x->parent == &sentinal)	root=y;
	else if(x == x->parent->left)	x->parent->left=y;
	else 	x->parent->right=y;
	
	y->left=x;
	x->parent=y;
}

void rbtree::rightRotate(node *x){
	node *y=x->left;
	x->left=y->right;
	
	if(y->right != &sentinal)	y->right->parent=x;
	
	y->parent=x->parent;
	
	if(x->parent == &sentinal)	root=y;
	else if(x == x->parent->right)	x->parent->right=y;
	else	x->parent->left=y;
	
	y->right=x;
	x->parent=y;
}

void rbtree::disp(){
	display(root);
}

void rbtree::display(node *x){
	if(root == &sentinal){
		cout<<"\nEmpty tree !!!";	return;
	}
	
	if(x != &sentinal){
		cout<<"\nNODE INFO : \n"<<"Key : "<<x->key<<"\nColor : ";
		
		if(x->color == 'b')		cout<<"Black";
		else	cout<<"Red";
		
		if(x->parent == &sentinal)	cout<<"\nSentinal is its parent : "<<x->parent->key;
		
		if(x->right != &sentinal)	cout<<"\nRight child : "<<x->right->key;
		else	cout<<"\nSentinal is the right child of the node. \n";
		
		if(x->left != &sentinal)	cout<<"\nLeft child : "<<x->left->key;
		else	cout<<"\nSentinal is the left child of the node. \n";
		}
}

void rbtree::insert(){
	int insertValue;
	cout<<"\nEnter key of the node to be inserted : ";
	cin>>insertValue;
	
	node *x, *y, *z=new node(insertValue, &sentinal);
	
	y=&sentinal;
	x=root;
	
	while(x != &sentinal){
		y=x;
		if(z->key < x->key)		x=x->left;
		else	x=x->right;	
	}
	
	z->parent=y;
	
	if(y == &sentinal)		root=z;
	else if(z->key < y->key)	y->left=z;
	else	y->right=z;
	
	z->left=&sentinal;
	z->right=&sentinal;
	z->color='r';
	
	insertFix(z);
}

void rbtree::insertFix(node *z){
	node *y;
	
	while(z->parent->color == 'r'){
		node *gp=z->parent->parent;
		
		if(z->parent->color == 'r'){
			y=gp->right;
			
			if(y->color == 'r'){
				z->parent->color='b';
				y->color='b';
				gp->color='r';
				z=gp;
			}
			else{
				if(z == z->parent->right){
					z=z->parent;
					leftRotate(z);
				}
				
				z->parent->color='b';
				gp->color='r';
				rightRotate(gp);
			}
		}
		else{
			y=gp->left;
			
			if(y->color == 'r'){
				z->parent->color='b';
				y->color='b';
				z=gp;
			}
			else{
				if(z == z->parent->left){
					z=z->parent;
					rightRotate(z);
				}
				
				z->parent->color='b';
				gp->color='r';
				leftRotate(gp);
			}
		}
	}
	
	root->color='b';
}

int main(){
	int ch, y=0;
	rbtree obj;
	
	do{
		cout<<"\n\t RED BLACK TREE \n";
		cout<<"\n1. Insert in the tree ";
		cout<<"\n2. Delete from the tree ";
		cout<<"\n3. Display the tree ";
		cout<<"\n4. Exit ";
		cout<<"\n5. Display a particular node ";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		
		switch(ch){
			case 1: {
				obj.insert();
				cout<<"\nNode inserted \n";
				break;
			}
			case 2: {
				obj.rb_delete();
				cout<<"\nNode deleted \n";
				break;
			}
			case 3: {
				obj.disp();
				break;
			}
			case 4: {
				y=1;
				break;
			}
			default: {
				cout<<"\nEnter a valid choice \n";
				break;
			}
		}
		
		cout<<"\n";
	}while(y != 1);
	
	return 1;
}

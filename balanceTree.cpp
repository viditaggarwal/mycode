#include<iostream>
#include<stack>
#include<stdlib.h>
using namespace std;

struct node{
	int data;
	node * right, *left;
}*root;

node *createNode(int n){
	node *nn = new node;
	nn->data = n;
	nn->left = NULL;
	nn->right = NULL;
	return nn;	
}

void addChild(node *ptr, int n){
	if(n <= ptr->data){
		if(ptr->left!=NULL){
			addChild(ptr->left, n);
		}else{
			ptr->left = createNode(n);
		}
	}else{
		if(ptr->right!=NULL){
			addChild(ptr->right, n);
		}else{
			ptr->right = createNode(n);
		}
	}
}

void insert(int n){
	if(root == NULL){
		root = new node;
		root->data = n;
		root->left = NULL;
		root->right = NULL;
	}else{
		addChild(root,n);		
	}
}

void nonRecInorder(node *ptr){
	node* stk[50];
	int top = -1;
	stk[++top] = NULL;
	while(1){
		if(ptr){
			stk[++top] = ptr;
			ptr = ptr->left;
		}else{
			ptr = stk[top--];
			if(ptr == NULL)return;
			cout<<ptr->data<<endl;
			if(ptr->right != NULL){
				ptr = ptr->right;
			}else{
				ptr = NULL;
			}
		}
	}
}

void nonRecPreorder(node *ptr){
	node *stk[50];
	int top = -1;
	stk[++top] = NULL;
	while(1){
		if(ptr){
			cout<<ptr->data<<endl;
			stk[++top] = ptr;
			ptr = ptr->left;
		}else{
			ptr = stk[top--];
			if(ptr == NULL)return;
			if(ptr->right){
				ptr = ptr->right;
			}else{
				ptr = NULL;
			}
		}
	}
	
}

void nonRecPostorder(node *ptr){
	node *stk[50];
	int top = -1;
	stk[++top] = NULL;
	while(1){
		if(ptr){
			stk[++top] = ptr;
			ptr = ptr->left;
		}else{
			ptr = stk[top--];
			if(ptr == NULL)return;
			if(ptr->right!=NULL){
				ptr = ptr->right;
			}else{
				
			}
		}
	}	
}

int maxH(int a, int b){
	return (a>b)?a:b;
}

int height(node *ptr){
	if(ptr == NULL)return 0;
	return maxH(height(ptr->left),height(ptr->right))+1;
}

bool checkBalance(node *ptr){
	int l = height(ptr->left);
	int r = height(ptr->right);
	cout<<l<<","<<r<<endl;
	if(abs(l-r)>1)return false;
	return true;
}

void inorder(node *ptr){
	if(ptr){
		inorder(ptr->left);
		cout<<ptr->data<<endl;
		inorder(ptr->right);
	}
}

void preorder(node *ptr){
	if(ptr){
		cout<<ptr->data<<endl;
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

int main(){
	root = NULL;
	insert(50);
	insert(30);
	insert(40);
	insert(20);
	insert(10);
	insert(80);
	insert(70);
	insert(90);
	cout<<height(root)<<endl;
	cout<<checkBalance(root)<<endl;
	//nonRecPreorder(root);
	//preorder(root);
	return 0;
}

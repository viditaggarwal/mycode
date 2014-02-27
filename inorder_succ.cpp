#include<iostream>
#include<math.h>
#include<limits.h>
#include<vector>
using namespace std;

struct node{
	int data;
	node *left, *right;	
}*root;

node *createNode(int n){
	node *nn = new node;
	nn->data = n;
	nn->left = NULL;
	nn->right = NULL;
	return nn;
}

void checkAndInsert(node *ptr, int n){
	if(n <=  ptr->data){
		if(ptr->left != NULL)checkAndInsert(ptr->left, n);
		else{
			node *nn = createNode(n);
			ptr->left = nn;
		}
	}else{
		if(ptr->right != NULL)checkAndInsert(ptr->right, n);
		else{
			node *nn = createNode(n);
			ptr->right = nn;
		}
	}	
}

void insert(int n){
	if(root == NULL){
		root = createNode(n);
	}else{
		checkAndInsert(root, n);
	}
}

void inorder(node *ptr){
	if(ptr){
		inorder(ptr->left);
		cout<<ptr->data<<"   ";
		inorder(ptr->right);
	}
}

int checkHeight(node *ptr){
	if(ptr == NULL)return 0;
//	int l = checkHeight(ptr->left);
//	int r = checkHeight(ptr->right);
//	if(l == -1)return -1;
//	if(r == -1)return -1;
//	if(abs(l-r) > 1)return -1;
//	else 
	return max(checkHeight(ptr->left), checkHeight(ptr->right))+1;
}

int inorder_succ_rec(node *ptr, int n, int par){
	node *parent = NULL, *tmp;
	if(n < ptr->data){
		par = inorder_succ_rec(ptr->left, n, ptr->data);
	}else{
		if(n > ptr->data){
			par = inorder_succ_rec(ptr->right, n, par);
		}else{
			if(par<ptr->data && !ptr->left && !ptr->right)return -1;
			if(ptr->right != NULL){
				tmp = ptr->right;
				while(tmp->left){
					tmp = tmp->left;
				}
				return tmp->data;
			}
		}
	}

	
	return par;
}

node *inorder_succ(node *ptr, int n){
	node *parent = NULL, *tmp;
	while(1){
		if(n < ptr->data){
			parent = ptr;
			ptr = ptr->left;
		}else{
			if(n > ptr->data){
				ptr = ptr->right;
			}else{
				break;
			}
		}
	}
	if(ptr->right != NULL){
		tmp = ptr->right;
		while(tmp->left){
			tmp = tmp->left;
		}
		return tmp;
	}
	return parent;
}


int main(){
	root = NULL;
	insert(50);
	insert(20);
	insert(70);
	insert(10);
	insert(40);
	insert(60);
	insert(80);
	insert(45);
	//const int height = checkHeight(root);
	//inorder(root);
	int nn = inorder_succ_rec(root,80, -1 );
	cout<<nn<<endl;
	return 0;
}

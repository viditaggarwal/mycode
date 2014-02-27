#include<iostream>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

struct node{
	int data;
	node *left, *right;
}*root;

node* newnode(int n){
	node *nn = new node;
	nn->data = n;
	nn->left = NULL;
	nn->right = NULL;
	return nn;
}

void checkAndInsert(node *ptr, int n){
	if(n <= ptr->data){
		if(!ptr->left)
			ptr->left = newnode(n);
		else
			checkAndInsert(ptr->left, n);			
	}else{
		if(!ptr->right)
			ptr->right = newnode(n);
		else
			checkAndInsert(ptr->right, n);		
	}
}

void insert(int n){
	if(root == NULL)
		root = newnode(n);
	else
		checkAndInsert(root, n);	
}

void inorder(node *ptr){
	if(ptr){
		inorder(ptr->left);
		cout<<ptr->data<<endl;
		inorder(ptr->right);
	}
}

int compare(int l, int root, int r){
	cout<<l<<","<<root<<","<<r<<endl;
	if(r == 0)return root;
	if(l<=root && r>root)return r;
	else return -1;
}

int checkBST(node *ptr){
	if(ptr){
		int l = checkBST(ptr->left);
		int r = checkBST(ptr->right);
		return compare(l, ptr->data, r);
	}else{
		return 0;
	}
}

int main(){
	int arr[] = {50,20,70,10,40,60,80,45};
	root = NULL;
	for(int i =0;i<8;i++){
		insert(arr[i]);
	}
	inorder(root);
	cout<<checkBST(root);
    return 0;    
}


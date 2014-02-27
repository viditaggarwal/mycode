#include<iostream>
#include<math.h>
using namespace std;

struct node{
	int data;
	node *left, *right;
}*root;

node *newNode(int n){
	node *nn = new node;
	nn->data = n;
	nn->left = NULL;
	nn->right = NULL;
}

void checkAndInsert(node *ptr, int n){
	if(n <= ptr->data){
		if(ptr->left == NULL)
			ptr->left = newNode(n);
		else
			checkAndInsert(ptr->left, n);
	}else{
		if(ptr->right == NULL)
			ptr->right = newNode(n);
		else
			checkAndInsert(ptr->right, n);
	}
}

void insert(int n){
	if(root == NULL){
		root = new node;
		root->data = n;
		root->left = NULL;
		root->right = NULL;
	}else{
		checkAndInsert(root, n);
	}
}

void inorder(node* ptr){
	if(ptr){
		inorder(ptr->left);
		cout<<ptr->data<<endl;
		inorder(ptr->right);
	}
}

int getHeight(node *ptr){
	if(ptr == NULL){
		return 0;
	}
	int l = getHeight(ptr->left);
	if(l == -1){
		return -1;
	}
	int r = getHeight(ptr->right);
	if(r == -1){
		return -1;
	}
	if(abs(l-r) > 1){
		return -1;
	}else{
		return max(l,r)+1;	
	}
}

bool isBalanced(node *root){
	if(getHeight(root) == -1){
		return false;
	}
	return true;
}

int main(){
	root = NULL;
	int arr[] = {50,30,80,40,20,70,90,15,10};
	for(int i=0;i<9;i++){
		insert(arr[i]);
	}
	//inorder(root);
	cout<<isBalanced(root)<<endl;
	return 0;
}

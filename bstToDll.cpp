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

void treeToDoublyList(node *p, node *&prev, node *&head) {
  if (!p) return;
  treeToDoublyList(p->left, prev, head);
  // current node's left points to previous node
  p->left = prev;
  if (prev)
    prev->right = p;  // previous node's right points to current node
  else
    head = p; // current node (smallest element) is head of
  // the list if previous node is not available
  // as soon as the recursion ends, the head's left pointer 
  // points to the last node, and the last node's right pointer
  // points to the head pointer.
  node *right = p->right;
  head->left = p;
  p->right = head;
  // updates previous node
  prev = p;
  treeToDoublyList(right, prev, head);
}

int inorder_succ_rec(node *ptr, int n, int par){
	if(n < ptr->data){
		par = inorder_succ_rec(ptr->left, n, ptr->data);
	}else{
		if(n > ptr->data){
			par = inorder_succ_rec(ptr->right, n, par);
		}else{
			if(ptr->right){
				node *tmp = ptr->right;
				while(tmp->left){
					tmp = tmp->left;
				}
				return tmp->data;
			}
		}
	}
	return par;
}

void convertToDLL(node *ptr, node *&l, node *&r){
	if(ptr){
		convertToDLL(ptr->left, l, r);
		if (l)
	    	l->right = ptr;  // previous node's right points to current node
		else
	    	r = ptr;
		node *right = ptr->right;
		r->left = ptr;
		ptr->right = r;
		l = ptr;
		convertToDLL(right, l, r);
	}			
}

void printDll(node *ptr){
	for(int i=0;i<8;i++){
		cout<<ptr->data<<endl;
		ptr = ptr->right;
	}
}

int main(){
	int arr[] = {50,20,70,10,40,60,80,45};
	root = NULL;
	for(int i =0;i<8;i++){
		insert(arr[i]);
	}
	node *p1 = NULL;
	node *p2 = NULL;
//	treeToDoublyList(root, p1, p2);
//	printDll(p2);
	convertToDLL(root, p1, p2);
	printDll(p2);
	//cout<<inorder_succ_rec(root, 80, -1);
	return 0;    
}


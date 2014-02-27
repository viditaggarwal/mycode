#include<iostream>
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

int inorder_succ(node* ptr, int n, int par){
	node *tmp = NULL;
	if(n < ptr->data){
		par = inorder_succ(ptr->left, n, ptr->data);
	}else{
		if(n>ptr->data){
			par = inorder_succ(ptr->right, n, par);
		}else{
			if(par<ptr->data && !ptr->left && !ptr->right)return -1;
			if(ptr->right!=NULL){
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

int main(){
	int arr[] = {50,20,70,10,40,60,80,45,33,32,31};
	root = NULL;
	for(int i =0;i<11;i++){
		insert(arr[i]);
	}
	//inorder(root);
	cout<<inorder_succ(root, 80, -1);
	return 0;
}

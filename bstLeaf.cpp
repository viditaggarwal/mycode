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

int visited = -1;
void LeftMostInEveryLevel (node *root, int level) {
     if (root != NULL) {
	 	 if (level > visited) {
             cout << "Level = " << level << ", Node = " << root->data << endl;
             visited = level;
    	 }
         LeftMostInEveryLevel (root->left, level + 1);
         LeftMostInEveryLevel (root->right, level + 1);
     }
}

int printLeaf(node *ptr,int leafLvl, int level, int k){
	if(!ptr)return -1;
	cout<<leafLvl<<","<<level<<endl;
	if(leafLvl - level == k){
		cout<<ptr->data<<endl;
	}
	if(!ptr->left && !ptr->right){
		return level;
	}else{
		leafLvl =  printLeaf(ptr->left, leafLvl, level+1, k);
		leafLvl =  printLeaf(ptr->right, leafLvl, level+1, k);
	}
}


int main(){
	int arr[] = {50,20,70,10,40,60,80,45};
	root = NULL;
	for(int i =0;i<8;i++){
		insert(arr[i]);
	}
	//inorder(root);
    cout<<printLeaf(root, 0, 0, 2);
	return 0;    
}


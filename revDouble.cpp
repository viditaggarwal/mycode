#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int data;
	node *left, *right;
};

void insert(node * fr, int n){
	if(fr->right == NULL){
		node *nn = new node;
		nn->data = n;
		fr->right = nn;
		nn->left = fr;
		nn->right = NULL;
	}else{
		node *nn = new node;
		nn->data = n;
		nn->right = fr->right;
		fr->right->left = nn;
		fr->right = nn;		
		nn->left = fr;		
	}
	
}

void printLL(node *fr){
	if(fr->right != NULL){
		cout<<fr->right->data<<endl;
		printLL(fr->right);
	}	
}

void swap(node * ptr){
	node *temp = new node;
	temp = ptr->left;
	ptr->left = ptr->right;
	ptr->right = temp;
}

void reverseLL(node *ptr){
	node *temp = ptr;
	while(ptr->right != NULL){
		ptr = ptr->right;
	}
	ptr->right = temp;
	temp->right = ptr;
	while(ptr->right != NULL){	
		if(ptr->left == temp){
			swap(ptr);
			ptr->right = NULL;
		}else{		
			swap(ptr);
			ptr = ptr->right;
		}
	}
	
}

int main(){
	node *front = new node;
	front->right = NULL;
	front->left = NULL;
	insert(front,10);
	insert(front,20);
	insert(front,30);
	insert(front,40);
	insert(front,50);
	insert(front,60);
	
	//printLL(front);
	reverseLL(front);
	printLL(front);
	return 0;
}

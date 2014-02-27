#include<iostream>
using namespace std;

struct node{
	int data;
	node *next;
};

void insert(int n){
	if(!head){
		head = new node;
		head->data = n;
		head->next = NULL;
	}else{
		node *nn = new node;
		nn->data = n;
		nn->next = head;
		head = nn;
	}
}

void printLL(node *ptr){
	if(ptr){
		cout<<ptr->data<<endl;
		printLL(ptr->next);
	}	
}
void convertLL(node *ptr, int n){
	node *curr =  
}

int main(){
	head = NULL;
	convertLL(head, 3);
	return 0;
}

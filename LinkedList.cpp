#include<iostream>
using namespace std;

struct node{
	int data;
	node *next;
}*head;

void insert(int n){
	if(head == NULL){
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

void print(node *ptr){
	if(ptr){
		cout<<ptr->data<<endl;
		print(ptr->next);
	}
}

node *partition(node *ptr, int n){	
	node *beforeS = NULL;
	node *beforeE = NULL;
	node *afterS = NULL;
	node *afterE = NULL;
	while(ptr!=NULL){
		node *next = ptr->next;
		ptr->next = NULL;
		if(ptr->data < n){
			if(beforeS == NULL){
				beforeS = ptr;
				beforeE = beforeS;
			}else{
				beforeE->next = ptr;
				beforeE = ptr;
			}
		}else{
			if(afterS == NULL){
				afterS = ptr;
				afterE = afterS;
			}else{
				afterE->next = ptr;
				afterE = ptr;
			}
		}
		ptr = next;
	}
	if(beforeS == NULL)return afterS;
	
	beforeE->next = afterS;
	return beforeS; 
}

int main(){
	head = NULL;
	insert(60);
	insert(50);
	insert(20);
	insert(40);
	insert(70);
	insert(80);
	insert(10);
	insert(30);
	//print(head);
	head = partition(head, 50);
	print(head);
	return 0;
}

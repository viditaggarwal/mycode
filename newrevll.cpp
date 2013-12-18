#include<iostream>
using namespace std;

struct node{
	int data;
	node * next;
}*head;

void insert(int n){
	if(head == NULL){
		node * nn = new node;
		nn->data = n;
		nn->next = NULL;
		head = nn;
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

void reverseLL(node *ptr){
	node *prev = ptr;
	node *curr = ptr->next;
	if(ptr->next->next){
		reverseLL(ptr->next);
	}else{
		head = curr;
	}
	curr->next = prev;
	prev->next = NULL;	
}

void iterRevLL(){
	node *prev = NULL;
	node *curr = head;
	node *temp;
	while(curr->next){
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
		cout<<"curr data in while is "<<curr->data<<endl;
	}
	cout<<"curr data"<<curr->next->data<<endl;
	head = prev;	
}

void reverseIte(){
	if (!head) return;
	node* prev = NULL;
	node* curr = head;
	while (curr) {
		node* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
  	head = prev;
}

int main(){
	head = NULL;
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	insert(50);
	reverseIte();
	print(head);
	return 0;
}

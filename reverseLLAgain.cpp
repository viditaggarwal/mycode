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

void printLL(node *ptr){
	if(ptr){
		cout<<ptr->data<<"  ";
		printLL(ptr->next);
	}
}

void reverseLLIter(){
	node *curr = head;
	node *prev = NULL;
	node *temp;
	while(1){
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;		
		if(!curr)break;
	}
	head = prev;
}

node* reverseLLRec(node *curr, node *prev){
	if(!curr)
		return prev;	
	node *temp = curr->next;
	curr->next = prev;
	return reverseLLRec(temp, curr);
}

int main(){
	head = NULL;
	insert(10);	
	insert(20);
	insert(30);
	insert(40);
	insert(50);	
	insert(60);
	insert(70);
	insert(80);
	//reverseLLIter();
	head = reverseLLRec(head, NULL);
	printLL(head);
	return 0;
}

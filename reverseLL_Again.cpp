#include<iostream>
using namespace std;

struct node{
	int data;
	node* next;
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

void insertNums(int *arr, int n){
	for(int i=0;i<n;i++){
		insert(arr[i]);
	}
}

void printLL(node *ptr){
	if(ptr){
		cout<<ptr->data<<endl;
		printLL(ptr->next);
	}
}

node* reverseLLRec(node *curr, node *prev){
	node *temp;
	if(curr){
		temp = curr->next;
		curr->next = prev;
		prev = reverseLLRec(temp, curr);
	}
	return prev;
}

void reverseLL(node *ptr){
	node *curr = ptr, *prev = NULL, *temp;
	while(curr){
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	head = prev;
}


int main(){
	head = NULL;
	int arr[] = {10,20,30,40,50,60,70};
	insertNums(arr, 7);
	
	//reverseLL(head);
	head = reverseLLRec(head, NULL);
	printLL(head);
	return 0;
}

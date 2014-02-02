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
		cout<<ptr->data<<endl;
		printLL(ptr->next);
	}
}

void removeDuplicate(){
	node *curr = head;
	node *runner = head;
	while(curr){
		runner = curr;
		while(runner->next != NULL){
			if(curr->data == runner->next->data){
				runner->next = runner->next->next;
			}
			runner = runner->next;
		}
		curr = curr->next;
	}	
}

void partition(int n){
	node *curr = head->next;
	node *prev = head;
	node *temp;
	while(curr){
		if(curr->data < n && curr != head){
			temp = curr;
			prev->next = temp->next;
			curr = curr->next;
			temp->next = head;
			head = temp;			
		}else{
			prev = curr;
			curr = curr->next;
		}
	}	
}

void palindrome(){
	node *curr
}

int main(){
	head = NULL;
	insert(10);
	insert(40);
	insert(70);
	insert(20);
	insert(80);
	insert(30);
	insert(50);
	//removeDuplicate();
	partition(45);
	printLL(head);
	return 0;
}

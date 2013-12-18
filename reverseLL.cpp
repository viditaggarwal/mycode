#include<iostream>
using namespace std;

struct ll{
	int d;
	ll* n;
}*head;

void insert(int n){
	if(head == NULL){
		head = new ll;
		head->d = n;
		head->n = NULL;
	}else{
		ll *newnode = new ll;
		newnode->d = n;
		newnode->n = head;
		head = newnode;
	}
}

void iterRevLL(){
	if(!head)return;
	ll *prev = NULL;
	ll *curr = head;
	//ll *temp;
	while(curr){
		ll* temp = curr->n;
		curr->n = prev;
		prev = curr;
		curr = temp;
		//cout<<"curr data in while is "<<curr->data<<endl;
	}
	//cout<<"curr data"<<curr->next->data<<endl;
	head = prev;	
}

/*void reverseLL(ll *ptr){
	if(ptr->n != NULL){
		//cout<<ptr->d<<endl;
		//cout<<ptr->n->d<<endl;
		reverseLL(ptr->n);
		if(ptr->n->n == NULL){
			head = ptr->n;
		}
		if(ptr == head){
			ptr->n = NULL;
		}
		ptr->n->n = ptr;		
		cout<<ptr->d<<endl;
	}
}*/

void reverse(ll* p) {
	if (!p) return;
	if (!p->n){
		head = p;
		return;
	}
	reverse(p->n);
	p->n->n = p;
	p->n = NULL;
}

void reverseIte(){
	if (!head) return;
	ll* prev = NULL;
	ll* curr = head;
	while (curr) {
		ll* next = curr->n;
		curr->n = prev;
		prev = curr;
		curr = next;
	}
  	head = prev;
}

void printLL(ll *ptr){
	if(ptr!=NULL){
		cout<<ptr->d<<endl;
		printLL(ptr->n);
	}
}

int main(){
	head = NULL;
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	insert(50);
	insert(60);
	//reverseIte();
	iterRevLL();
	printLL(head);
	return 0;
}

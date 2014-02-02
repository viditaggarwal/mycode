#include<iostream>
using namespace std;

int list1Sz = 0;
int list2Sz = 0;

struct node{
	int data;
	node* next;
}*list1,*list2;

node *insert(node *head, int n){
	if(head == NULL){
		cout<<"head"<<endl;
		head = new node;
		head->data = n;
		head->next = NULL;
	}else{
		node *nn = new node;
		nn->data = n;
		nn->next = head;
		head = nn;
	}
	return head;
}

node *insertEnd(node *head, int n){
	node *tmp = head;
	if(head == NULL){
		cout<<"head"<<endl;
		head = new node;
		head->data = n;
		head->next = NULL;
	}else{
		while(tmp->next!=NULL){
			tmp = tmp->next;
		}
		node *nn = new node;
		nn->data = n;
		nn->next = NULL;
		tmp->next = nn;
	}
	return head;
}

node* add(node *h1, node *h2){
	int sum, carry = 0;
	node *result = NULL;
	if(list1Sz == list2Sz){
		cout<<"Inside if"<<endl;
		if(!h1)cout<<"h1 is NULL"<<endl;
		while(h1!= NULL){
			cout<<"h1 and h2"<<endl;
			sum = h1->data+h2->data+carry;
			carry = sum/10;
			sum = sum%10;
			result = insert(result, sum);
			h1 = h1->next;
			h2 = h2->next;
		}
	}else{
		cout<<"else"<<endl;
		if(list1Sz>list2Sz){
			list2 = insertEnd(list2, 0);	
			list2Sz++;
		}else{
			list1 = insertEnd(list1, 0);
			list1Sz++;
		}		
		result = add(list1, list2);
	}
	return result;
}

void printList(node *ptr){
	if(ptr){
		cout<<ptr->data<<"   ";
		printList(ptr->next);	
	}
}

int main(){
	list1 = NULL;
	list2 = NULL;
	list1 = insert(list1, 6);
	list1Sz++;
	list1 = insert(list1, 1);
	list1Sz++;
	list1 = insert(list1, 7);
	list1Sz++;
	list2 = insert(list2, 2);
	list2Sz++;
	list2 = insert(list2, 9);
	list2Sz++;
	//printList(list1);
	//printList(list2);
	node* res = add(list1, list2);
	printList(res);
	return 0;
}

#include<iostream>
using namespace std;

struct node{
	int data;
	node* next;
}*head;

void *insert(int n){
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

class Result{
	
	public:
		node *nd;
		bool result;
		Result(node *nod, bool b){
			nd = nod;
			result = b;
		}	
		
};

Result *checkPalindrome(node *head, int length){
	if (head == NULL || length == 8) {
		return new Result(NULL, true);
	} else if (length == 1) {
		return new Result(head->next, true);
	} else if (length == 2) {
		return new Result(head->next->next,
		head->data == head->next->data);
	}
	Result *res = checkPalindrome(head->next, length - 2);
	if (!res->result || res->nd == NULL) {
		return res;
	} else {
		res->result = head->data == res->nd->data;
		res->nd = res->nd->next;
		return res;
	}
}

int main(){
	head = NULL;
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(3);
	insert(2);
	insert(1);
	//printLL(head);
	cout<<checkPalindrome(head, 7)->result<<endl;
	return 0;
}

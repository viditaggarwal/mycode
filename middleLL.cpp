#include<iostream>
using namespace std;

struct node{
	int data;
	node *next;
}*head;

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

node* middleLL(node *slow, node *fast){
	if(fast->next && fast->next->next){
			slow = slow->next;
			fast = fast->next->next;
			middleLL(slow, fast);
	}else{
		return slow;
	}	
}

class result{
	public:
	node *ptr;
	bool res;
	result(node *p, bool b){
		ptr = p;
		res = b;
	}
};

result *palindrome(node *head, int length){
	if(length == 0){
		return new result(NULL, true);	
	}else if(length == 1){
		return new result(head->next, true);
	}else if(length == 2){
		return new result(head->next->next, head->next->data == head->data);
	}else{
		result *res = palindrome(head->next, length - 2);
		if(!res->res || !res->ptr){
			return res;
		}else{
			res->res = head->data == res->ptr->data;
			res->ptr = res->ptr->next;
			return res; 
		}
	}
}


int main(){
	head = NULL;
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	insert(30);
	insert(20);
	insert(10);
	result *res = palindrome(head, 7);
	cout<<res->res<<endl;
	//cout<<middleLL(head, head)->data<<endl;	
	return 0;
}

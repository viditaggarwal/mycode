#include<iostream>
#include<stack>
using namespace std;

stack<int> stk;

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

bool checkPalindrome(){
	node *slow = head, *fast = head;
	while(fast != NULL){
		stk.push(slow->data);
		slow = slow->next;
		fast = fast->next->next;
	}
	while(!stk.empty()){
		if(stk.top() == slow->data){
			stk.pop();
		}
		else return false;
		slow = slow->next;
	}
	return true;
}
int cnt = 1;
bool flag = true;
node* checkPalindromeRec(node *slow, node *fast){
	node *temp = slow;
	if(fast != NULL){
		slow = checkPalindromeRec(slow->next, fast->next->next);
		cout<<slow->data<<" "<<temp->data<<endl;
		if(slow->data != temp->data)flag = false;
		if(slow->next!=NULL)return slow->next;
		else return NULL;
	}
}

void printStk(stack<int> st){
	while(!st.empty()){
		cout<<st.top()<<endl;
		st.pop();
	}
}

int main(){
	head = NULL;
	insert(80);	
	insert(70);
	insert(60);
	insert(50);
	insert(50);	
	insert(60);
	insert(70);
	insert(80);
	checkPalindromeRec(head, head);
	cout<<flag<<endl;
	//cout<<checkPalindrome()<<endl;
	//printStk(stk);
	
	//reverseLLIter();
	//head = reverseLLRec(head, NULL);
	//printLL(head);	
	return 0;
}

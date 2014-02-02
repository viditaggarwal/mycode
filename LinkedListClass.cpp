#include<iostream>
using namespace std;

class node{
	int data;
	node *next;	
	public:
		node(){
			
		}
		node(int n){
			this->data = n;
			this->next = NULL;
		}
		node *insert(node *first, int n){
			if(first == NULL){
				first = new node(n);
			}else{
				node *nn = new node(n);
				nn->next = first;
				first = nn;
			}
			return first;
		}		
		
		void printList(node *ptr){
			if(ptr){
				cout<<ptr->data<<endl;
				printList(ptr->next);
			}
		}
		
		node *insertAtTheEnd(node *first, int n){
			node *temp = first;
			if(first == NULL){
				first = new node(n);
			}else{
				while(temp->next != NULL){
					temp = temp->next;
				}
				node *nn = new node(n);
				temp->next = nn;
			}
			return first;
		}
		
		node* merge(node *head1, node *head2){
			node *head3 = NULL;
			while(head1!=NULL || head2!=NULL){
				if(head1->data > head2->data){
					cout<<"head1"<<endl;
					head3 = insertAtTheEnd(head3, head1->data);
					head1 = head1->next;
				}else{
					cout<<"head2"<<endl;
					head3 = insertAtTheEnd(head3, head2->data);
					head2 = head2->next;										
				}
				if(!head1){
					head3 = insertAtTheEnd(head3, head2->data);
					head2 = head2->next;
				}
				if(!head2){
					head3 = insertAtTheEnd(head3, head1->data);
					head1 = head1->next;
				}
			}
			return head3;
		}
		
		node *mergeRecursive(node *head1, node* head2, node *head3){
			if(head3==NULL){
				head3 = new node();
			}
			if(!head1 && !head2)return NULL;
			if(head1 && head2){
				if(head1->data > head2->data){
					head3 = mergeRecursive(head1->next, head2, head3);
					head3 = insert(head3, head1->data);
				}else{
					head3 = mergeRecursive(head1, head2->next, head3);
					head3 = insert(head3, head2->data);
				}
			}else{
				if(!head1){
					head3 = mergeRecursive(head1, head2->next, head3);
					head3 = insert(head3, head2->data);
				}else{
					if(!head2){
						head3 = mergeRecursive(head1->next, head2, head3);
						head3 = insert(head3, head1->data);
					}
				}
			}
			return head3;
		}
};

int main(){
	node *head1 = new node(10);
	head1 = head1->insert(head1,20);
	head1 = head1->insert(head1,30);
	head1 = head1->insert(head1,40);
	head1 = head1->insert(head1,50);
	//head1->printList(head1);
	node *head2 = new node(15);
	head2 = head2->insert(head2,25);
	head2 = head2->insert(head2,35);
	head2 = head2->insert(head2,45);
	head2 = head2->insert(head2,55);
	//head1->printList(head2);
	//node *head3 = head1->merge(head1, head2);
	node *head3 = head1->mergeRecursive(head1, head2, head3); 
	head1->printList(head3);
	return 0;
}

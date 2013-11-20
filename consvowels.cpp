#include<iostream>
using namespace std;

template <class T>
class linkedlist{
	private:
		T data;
		linkedlist* next;
	public:
		linkedlist* create(T n){
			linkedlist *nn = new linkedlist;
			nn->data = n;
			nn->next = NULL;
			return nn;
		}
		
		void insert(T n){
			if(this == NULL){
				this->next =  create(n);
			}else{
				linkedlist *nn = create(n);
				nn->next = this->next;
				this->next = nn;
			}	
		}
		
		void printList(linkedlist *ptr){
			if(ptr!=NULL){
				printList(ptr->next);
				cout<<ptr->data<<endl;
			}			
		}
};

int main(){
	linkedlist<char> *front;
	front->insert('n');	
	front->insert('5');
	front->insert('n');
	front->insert('o');
	front->insert('b');
	front->insert('2');
	front->insert('a');
	front->insert('5');
	front->insert('a');
	front->insert('2');
	front->printList(front->next);
	return 0;
}

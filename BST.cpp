#include <iostream>
#include <stdlib.h>
using namespace std;

struct node{
       int data;
       node *left, *right, *root;              
};

node *createNode(int n){
     node *newnode = new node;
     newnode->right = NULL;
     newnode->left = NULL;
     newnode->data = n;
     return newnode;
}

void check(node *root, int n){
     node *temp = root;
     while(temp != NULL){
          if(n >= temp->data){
               if(temp->right!=NULL){
                    temp = temp->right;
               }else{
               		node *nn = createNode(n);
                    temp->right = nn;
					break;       
               }
                    
          }else{
          		if(temp->left != NULL){
                    temp = temp->left;     
                }else{
                	node *nn = createNode(n);
					temp->left = nn;
					break;       
                }
          }                  
     }
}

void insert(node *T, int n){
     if(T->root == NULL){
     	   T->root = createNode(n);                      
     }else{
     	   check(T->root, n);      
     }
}

void inorder(node *T){
	if(T != NULL){
		inorder(T->left);		
		cout<<T->data<<endl;
		inorder(T->right);
					
	}	
}

void postorder(node *T){
	if(T != NULL){
		postorder(T->left);			
		postorder(T->right);			
		cout<<T->data<<endl;		
	}	
}

void preorder(node *T){
	if(T != NULL){
		cout<<T->data<<endl;
		postorder(T->left);			
		postorder(T->right);	
	}	
}

bool search(node *T, int n){
	if(T!=NULL){	
		if(T->data == n){
			cout<<"equal"<<T->data<<endl;
			return true;
		}
		else{	
		//cout<<"search is "<<search(T->left, n)<<endl;
			if( n < T->data && T->left != NULL){
				cout<<"less"<<endl;
				//cout<<"search is "<<search(T->left, n)<<endl;
				if(search(T->left, n) == 1)return true;
				else return false;
			}else{
				if(n > T->data && T->right != NULL){
					cout<<"greater"<<endl;
					if(search(T->right, n) == 1)return true;
					else return false;
				}
			}
			return false;
		}
	}
}


int main(){
    node *T = new node;
    T->root = NULL;
	insert(T,30);
	insert(T,20);
	insert(T,50);
	insert(T,40);
	//cout<<search(T->root, 40)<<endl;
	//cout<<search(T->root, 20)<<endl;
	//cout<<search(T->root, 50)<<endl;
	//cout<<search(T->root, 49)<<endl;
	//inorder(T->root);
	//preorder(T->root);
	//postorder(T->root);
	//cout<<T->root->left->data<<endl;
    system("pause");  
    return 0;    
}


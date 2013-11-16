#include <iostream>
#include <stdlib.h>
#include <stack>
#include<queue>
using namespace std;



struct node{
       int data;
       node *left, *right, *root;              
};

queue<node*> q;
queue<node*> val;
queue<node*> inq;
queue<node*> emp;


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
		//inq.push(T);
		preorder(T->left);			
		preorder(T->right);	
	}	
}

bool search(node *T, int n){
	if(T!=NULL){	
		if(T->data == n){
			return true;
		}
		else{	
			if( n < T->data && T->left != NULL){
				if(search(T->left, n) == 1)return true;
				else return false;
			}else{
				if(n > T->data && T->right != NULL){
					if(search(T->right, n) == 1)return true;
					else return false;
				}
			}
			return false;
		}
	}
}

node *lca(node *root, int n1, int n2){
	if (root == NULL) return NULL;
 
    if (root->data > n1 && root->data > n2)
        return lca(root->left, n1, n2);
 
    if (root->data < n1 && root->data < n2)
        return lca(root->right, n1, n2);
 
    return root;	
}


void nonrecinorder(node *ptr){
	int top =0;
    node* stack[50];
    stack[0] = NULL;
	while(1)
     {
     	if(ptr != NULL )
        {
     	   stack[++top] = ptr;
           ptr = ptr->left;
        }else{
           ptr = stack[top--];
           if( ptr == NULL)
              return;
           cout<<"  "<<ptr->data;
           if(ptr->right != NULL)
              ptr = ptr->right;
           else
              ptr = NULL;
        }
     }
     //return stack;
}

void nonrecpreorder(node *ptr){
	int top=0;
	node *stack[50];
	stack[0] = NULL;
	while(1){
		if(ptr!=NULL){
			cout<<ptr->data<<endl;
			stack[++top] = ptr;	
			ptr = ptr->left;
		}else{
           ptr = stack[top--];
           if( ptr == NULL)
              return;
           if(ptr->right != NULL)
              ptr = ptr->right;
           else
              ptr = NULL;
        }
	}
}

void nonrecpostorder(node *ptr){
	int top=0;
	node *stack[50];
	stack[0] = NULL;
	node *prev = NULL;
	while(1){
		if(ptr!=NULL){
			stack[++top] = ptr;	
			ptr = ptr->left;			
		}else{		   
           ptr = stack[top];
		   if( ptr == NULL)
              return;           
           if(ptr->right != NULL && ptr->right != prev){
			  ptr = ptr->right;
           }else{
           	   top--;
           	   cout<<ptr->data<<endl;
           	   prev = ptr;
		       ptr = NULL;  
      	   }
        }
	}
}


void printqueue(queue<node*> qp){
	while(!qp.empty()){
		cout<<(qp.front())->data<<endl;
		qp.pop();
	}
}

void bfs(node *ptr){	
	q.push(ptr);
	while(!q.empty()){
		node *nd = q.front();
		val.push(nd);
		q.pop();
		if(nd->left != NULL || nd ->right!=NULL){
			if(nd->left != NULL){
				q.push(nd->left);
			}
			if(nd->right != NULL){
				q.push(nd->right);
			}			
		}		
	}
}

void checkMirror(node *root, int n){
     node *temp = root;
     while(temp != NULL){
          if(n >= temp->data){
               if(temp->left!=NULL){
                    temp = temp->left;
               }else{
               		node *nn = createNode(n);
                    temp->left = nn;
					break;       
               }
                    
          }else{
          		if(temp->right != NULL){
                    temp = temp->right;     
                }else{
                	node *nn = createNode(n);
					temp->right = nn;
					break;       
                }
          }                  
     }
}

void insertMirror(node *T, int n){
     if(T->root == NULL){
     	   T->root = createNode(n);                      
     }else{
     	   checkMirror(T->root, n);      
     }
}

void createMirror(node* ptr){
	while(!val.empty()){
		insertMirror(ptr,(val.front())->data);
		val.pop();	
	}
	
}

int main(){
	node *T = new node;
    T->root = NULL;
	insert(T,30);
	insert(T,20);
	insert(T,50);
	insert(T,10);
	insert(T,15);
	insert(T,25);
	insert(T,35);
	insert(T,5);
	insert(T,60);
	insert(T,32);
	preorder(T->root);
	bfs(T->root);
	node* mir = new node;
	mir->root=NULL;
	createMirror(mir);
	preorder(mir->root);
	//swap(inq, emp);
	//preorder(T->root);
	printqueue(val);
	system("pause");
    return 0;    
}


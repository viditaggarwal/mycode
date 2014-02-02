#include<iostream>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<vector>
using namespace std;


struct node{
       int data;
       node *left, *right, *root;              
};

struct result{
	node *nd;
	int level=0;
};


queue<node*> q;
queue<node*> val;
queue<node*> inq;
queue<node*> emp;
queue<node*> temp;
vector<node*> listVec;
int cntr = 0;
int lvl=0;
int level = 0;

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
	if(T){	
		if(T->data == n)return true;		
		else{
			if( n < T->data && T->left)return search(T->left, n);
			else{
				if(n > T->data && T->right)	return search(T->right, n);
			}
			return false;
		}
	}
}

node *lca(node *root, int n1, int n2){
	if (!root) return NULL; 
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

result* checkLevel(node *root){
	result *l;
	result *r;
	if(root->left == NULL && root->right == NULL){
		result *rt = new result;
		rt->nd=root;
		rt->level = lvl;
		return rt;
	}
	if(root->left!=NULL){
		l = checkLevel(root->left);
		l->level++;
		lvl = l->level;
	}	
	if(root->right!=NULL){
		r = checkLevel(root->right);
		r->level++;
		lvl = r->level;
	}
	if(l->level <= r->level){
		return l;
	}else{
		return r;
	}
}

void checkBinary(node *root, int n){
	result *s = checkLevel(root);
	node *nn = createNode(n);
	
}

void insertBinary(node *root, int n){
	if(root == NULL){
		root->data = n;		
	}else{
		checkBinary(root,n);
	}
}

int visited = -1;
void LeftMostInEveryLevel (node *root, int level) {
     if (root != NULL) {
              if (level > visited) {
                        cout << "Level = " << level << ", Node = " << root->data << endl;
                        visited = level;
              }
              LeftMostInEveryLevel (root->left, level + 1);
              LeftMostInEveryLevel (root->right, level + 1);
     }
}

void convertLinkedList(node *ptr){
	q.push(ptr);
	cntr = 1;
	while(!q.empty()){		
		level++;
		int sz = cntr;
		cntr = 0;
		node *head = NULL;
		node *prev = NULL;
		for(int i = 0;i<sz;i++){
			node *nd = q.front();
			node *nn1 = new node;
			nn1->data = q.front()->data;
			nn1->right = NULL;
			q.pop();			
			if(head == NULL){
				head = nn1;
				prev = nn1;
			}else{
				prev->right = nn1;
				prev = nn1;
			}
			if(nd->left != NULL || nd->right!=NULL){
				if(nd->left != NULL){
					q.push(nd->left);
					cntr++;
				}
				if(nd->right != NULL){
					q.push(nd->right);
					cntr++;
				}
			}
		}
		listVec.push_back(head);	
	}	
}

void printLL(node *ptr){
	if(ptr){
		cout<<ptr->data<<endl;
		printLL(ptr->right);
	}
}

bool checkForSubtree(node *head, node *subHead){
	bool l,r;
	if(subHead){
		if(head->data == subHead->data){
			if(subHead->left){
				l = checkForSubtree(head->left, subHead->left);
			}else l = true;
			if(subHead->right){
				r = checkForSubtree(head->right, subHead->right);
			}else r = true;
			if(l&&r)return true;
			else return false;
		}else{
			return false;
		}
	}
}

bool checkSubtree(node *head, node *subHead){
	bool left = false, right=false;
	if(head){
		if(head->data == subHead->data){
			if(checkForSubtree(head, subHead))return true;
			else{
				left = checkSubtree(head->left, subHead);
				right = checkSubtree(head->right, subHead);
			}
		}else{
			left = checkSubtree(head->left, subHead);
			right = checkSubtree(head->right, subHead);
		}
	}
	if(left || right)return true;
	else return false;
}

int main(){
	node *T = new node;
    T->root = NULL;
	insert(T,30);
	insert(T,20);
	insert(T,50);
	insert(T,50);
	insert(T,10);
	//insert(T,15);
	insert(T,25);
	insert(T,35);
	insert(T,60);
	
	node *S = new node;
    S->root = NULL;
	insert(S,50);
	insert(S,60);
	cout<<checkSubtree(T->root, S->root);
	//cout<<search(T->root, 50);
	//insert(T,32);
	//insert(T,31);
	//result *r = checkLevel(T->root);
	//cout<<r->nd->data<<endl;
	//LeftMostInEveryLevel(T->root, 0);
	//preorder(T->root);
	//bfs(T->root);
	//node* mir = new node;
	//mir->root=NULL;
	//createMirror(mir);
	//preorder(mir->root);
	//swap(inq, emp);
	//preorder(T->root);
	//convertLinkedList(T->root);
	/*for(int i=0;i<listVec.size();i++){
		cout<<"level is "<<i<<endl;
		printLL(listVec[i]);
	}*/
	//printqueue(val);
	system("pause");
    return 0;    
}


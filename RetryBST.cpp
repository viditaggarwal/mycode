#include<iostream>
#include<math.h>
#include<limits.h>
#include<vector>
using namespace std;

struct node{
	int data;
	node *left, *right;	
}*root;

node *createNode(int n){
	node *nn = new node;
	nn->data = n;
	nn->left = NULL;
	nn->right = NULL;
	return nn;
}

void checkAndInsert(node *ptr, int n){
	if(n <=  ptr->data){
		if(ptr->left != NULL)checkAndInsert(ptr->left, n);
		else{
			node *nn = createNode(n);
			ptr->left = nn;
		}
	}else{
		if(ptr->right != NULL)checkAndInsert(ptr->right, n);
		else{
			node *nn = createNode(n);
			ptr->right = nn;
		}
	}	
}

void insert(int n){
	if(root == NULL){
		root = createNode(n);
	}else{
		checkAndInsert(root, n);
	}
}

void inorder(node *ptr){
	if(ptr){
		inorder(ptr->left);
		cout<<ptr->data<<"   ";
		inorder(ptr->right);
	}
}

int checkHeight(node *ptr){
	if(ptr == NULL)return 0;
//	int l = checkHeight(ptr->left);
//	int r = checkHeight(ptr->right);
//	if(l == -1)return -1;
//	if(r == -1)return -1;
//	if(abs(l-r) > 1)return -1;
//	else 
	return max(checkHeight(ptr->left), checkHeight(ptr->right))+1;
}

void createBalancedTree(int *arr, int start, int end){
	if(!(start > end)){
		int mid = (start+end)/2;
		cout<<mid<<endl;
		//if(arr[mid] == 0)cout<<mid<<endl;
		insert(arr[mid]);
		createBalancedTree(arr, start, mid-1);
		createBalancedTree(arr, mid+1, end);			
	}		
}

void printPath(int* path, int start, int end){
	for(int i=start;i<=end;i++){
		cout<<path[i]<<"  "<<endl;
	}
}
int cnt = 0;
void findSum(node *ptr, int sum, int* path, int level){
	if(ptr == NULL){
		return;
	}
	path[level] = ptr->data;
	int t = 0;
	for(int i=level;i>=0;i--){
		t += path[i];
		if(t == sum){
			cnt++;
			printPath(path, i, level);
		}
	}	
	findSum(ptr->left, sum, path, level+1);
	findSum(ptr->right, sum, path, level+1);
	path[level] = INT_MIN;
}

int main(){
	root = NULL;
//	int arr[] = {10,20,30,40,50,60,70,80,90};
//	createBalancedTree(arr,0, 8);
//	inorder(root);
	insert(1);
	insert(1);
	insert(1);
	insert(1);
	insert(1);
	insert(1);
	insert(1);
	insert(1);
	//insert(100);
	const int height = checkHeight(root);
	int* path = new int[height];
	findSum(root, 2, path, 0);
	cout<<cnt<<endl;
	//insert(110);
	//cout<<checkHeight(root)<<endl;
	//inorder(root);
	return 0;
}

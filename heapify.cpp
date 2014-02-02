#include<iostream>
using namespace std;

int sz = 8;

int findParent(int n){
	if((n-1)%2 == 0)return 1;
	else return 2;
}

void heapifyUp(int *arr, int n){
	int parent;
	int hand = findParent(n);
	if(hand == 1){
		parent = (n-1)/2;
	}else{
		parent = (n-2)/2;
	}
	if(n>=1){
		if(arr[parent] < ){
			cout<<"swap"<<arr[n]<<","<<arr[parent]<<endl;
			swap(arr[n], arr[parent]);
			heapifyDown(arr, parent);
		}
		heapifyUp(arr, n-1);
	}
	
}

int minOfChild(int *arr, int j){
	if(2*j+1>=sz)return -1;
	if(((2*j + 1) < sz) && ((2*j + 2)>=sz)){
		return 2*j+1;
	}else{
		if((2*j+2)<sz){
			return arr[2*j+1]<=arr[2*j+2]?(2*j+1):(2*j+2);
		}
	}
}

void heapifyDown(int *arr, int j){
	if(j<sz){
		int child = minOfChild(arr,j);
		if(arr[j]>arr[child] && child!=-1){
			cout<<"swap"<<j<<","<<child<<endl;
			swap(arr[j], arr[child]);
			if(2*child+1<sz){
				heapifyDown(arr, child);
			}
		}
		//heapifyDown(arr, j+1);
	}
}

void print(int* arr, int n){
	for(int i=0;i<=n;i++){
		cout<<arr[i]<<"	";
	}
}

int main(){
	int a[] = {50,30,60,10,70,40,20,80};
	heapifyDown(a,0);	
	print(a,7);
	return 0;
}

#include<iostream>
using namespace std;

int left(int i){
	return 2*i+1;
}

int right(int i){
	return 2*i+2;
}

void maxHeapify(int *arr, int i,int n){
	int largest;
	int l = left(i);
	int r = right(i);
	if(l < n && arr[l] > arr[i]){
		largest = l;
	}else{
		largest = i;
	}
	if(r < n && arr[r] > arr[largest]){
		largest = r;
	}
	if(largest != i){
		swap(arr[i], arr[largest]);
		maxHeapify(arr, largest, n);
	}
}

void binaryHeap(int *arr, int n){
	for(int i=n/2;i>=0;i--){
		maxHeapify(arr, i, n);
	}
}

void printarr(int *arr, int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<endl;
	}
}

int main(){
	int arr[] = {30,40,80,20,50,10,60,100};
	binaryHeap(arr, 8);
	printarr(arr, 8);	
	return 0;
}

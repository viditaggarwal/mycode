#include<iostream>
using namespace std;



void maxHeapify(int *arr, int i, int n){
	int largest;
	int l = 2*i+1;
	int r = 2*i+2;
	if(l < n && arr[l] > arr[i]){
		largest = l;
	}else{
		largest = i;
	}
	if( r<n && arr[r] > arr[largest]){
		largest = r;
	}
	if(largest  != i){
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
	int arr[] = {40,30,50,60,70,90,10,20};
	binaryHeap(arr, 8);
	printarr(arr,8);
	return 0;
}

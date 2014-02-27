#include<iostream>
using namespace std;

void searchHeap(int n){
	
}

int left(int i){
	return 2*i+1;
}

int right(int i){
	return 2*i+2;
}

void minHeapify(int *arr,int i, int n){
	int l = left (i);
	int r = right (i);
	int smallest;
	if(l < n && arr[l]<arr[i]){
		smallest = l;
	}else{
    	smallest = i;
    }   
	if(r < n && arr[r]<arr[ smallest ]){
		smallest = r;
	}
    if(smallest != i){
    	swap(arr[i], arr[smallest]);
    	minHeapify(arr, smallest, n);
	}
}

void maxHeapify(int *arr,int i, int n){
	int l = left (i);
	int r = right (i);
	int largest;
	if(l < n && arr[l]>arr[i]){
		largest = l;
	}else{
    	largest = i;
    }   
	if(r < n && arr[r]>arr[ largest ]){
		largest = r;
	}
    if(largest != i){
    	swap(arr[i], arr[largest]);
    	maxHeapify(arr, largest, n);
	}
}

void buildHeap(int *arr, int n){
	for(int i=(n/2);i>=0;i--){
		maxHeapify(arr,i,n);
	}
}

void printarr(int *arr, int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<endl;
	}
}

int main(){
	int arr[] = {30,40,80,20,50,10,60,100};
	buildHeap(arr, 8);
	printarr(arr, 8);
	//searchHeap();	
	return 0;
}

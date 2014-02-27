#include<iostream>
using namespace std;

void maxHeap(int arr[], int i, int n){
	cout<<"index is "<<i<<endl;
	int l = 2*i+1;
	int r = 2*i+2;
	int largest;
	if(l < n && arr[l] > arr[i]){
		largest = l;
	}else{
		largest = i;
	}
	if(r < n && arr[r] > arr[largest]){
		largest = r;
	}
	if(largest != i){
		swap(arr[largest], arr[i]);
		maxHeap(arr, largest, n);
	}	
}

void binaryHeap(int arr[], int n){
	for(int i = n/2;i>=0;i--){
		maxHeap(arr, i, n);
	}	
}

void printarr(int arr[], int n){
	for(int i =0;i<n;i++){
		cout<<arr[i]<<"   ";
	}
}

int main(){
	int arr[] = {20,50,10,40,80,0,100,30};
	int n = sizeof(arr)/sizeof(int);
	cout<<n<<endl;
	binaryHeap(arr, n);
	printarr(arr, n);
	return 0;
}

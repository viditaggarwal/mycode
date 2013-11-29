#include<iostream>
using namespace std;

void swap(int &a, int &b){
	cout<<"swap "<<a<<","<<b<<endl;
	int temp = a;
	a=b;
	b=temp;
}

void printarr(int *arr){
	for(int i=0;i<8;i++){
		cout<<arr[i]<<"    ";
	}
	cout<<endl;
}

int partition(int *arr, int low, int high){
	int pivot = low;
	int i = low;
	int j = high;
	while(i<j){
		while(arr[i]<=arr[pivot] && i<high){
			i++;
		}
		while(arr[j]>arr[pivot]){
			j--;
		}
		if(i<j)
	    { 
	   		swap(arr[i], arr[j]);
	    }		
	}
	swap(arr[j],arr[pivot]);
	printarr(arr);
	return j;
}

void quicksort(int *a, int low, int high){
	if(low<high){
		int p = partition(a, low, high);
		quicksort(a, low, p-1);
		quicksort(a,p+1,high);
	}
}

int main(){
	int a[] = {5,4,7,2,8,3,1,6};
	quicksort(a, 0, 7);
	return 1;
}

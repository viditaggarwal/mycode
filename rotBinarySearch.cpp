#include<iostream>
using namespace std;

int binarySearch(int *arr, int n, int start, int end){
	int mid = start+(end - start)/2;
	if(start<end){
		if(n < arr[mid]){
			if(n < arr[start])return binarySearch(arr, n, mid+1, end);
			else return binarySearch(arr, n, start, mid-1);			
		}else{
			if(n == arr[mid])return mid;
			else{
				if(n < arr[end])return binarySearch(arr, n, mid+1, end);
				else return binarySearch(arr, n, start, mid-1);				
			}
		}
	}
}

int main(){
	int arr[] = {15,16,19,20,25,1,3,4,5,7,10,14};
	cout<<binarySearch(arr, 5, 0, 11);
	return 0;
}

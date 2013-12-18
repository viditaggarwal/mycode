#include<iostream>
using namespace std;

void merge(int *arr, int *buff, int start, int end){
	cout<<"start is "<<start<<", end is "<<end<<endl;
	int fir = start;
	int mid = (start+end)/2;
	int sec = mid+1;
	int ctr = start;
	while(fir<=mid && sec<=end){
		if(arr[fir] <= arr[sec]){
			buff[ctr] = arr[fir];
			fir++;
		}else{
			buff[ctr] = arr[sec];
			sec++;
		}
		ctr++;		
	}
	if(fir>mid){
		for(int i=sec;i<=end;i++){
			buff[ctr] = arr[i];
			ctr++;
		}
	}else{
		for(int i=fir;i<=mid;i++){
			buff[ctr] = arr[i];
			ctr++;
		}
	}
	for(int k=start; k<=end; k++) arr[k]=buff[k];
}


void mergesort(int *arr,int* buff, int start, int end){
	if(start<end){
		int mid = (start+end)/2;
				
		mergesort(arr, buff, start, mid);
		mergesort(arr, buff, mid+1, end);
		merge(arr, buff, start, end);
	}
}

void print(int *arr, int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"   ";
	}
}

int main(){
	int arr[] = { 30, 20, 40, 80, 10, 90, 50, 70 };
	int *buff = new int[8];
	int n = 8;
	mergesort(arr, buff, 0,n-1);
	print(arr, n);
	return 0;
}

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

int pivot(int *arr, int start, int end){
	int p = start;
	int i=start;
	int j=end;
	int v = arr[p];
	cout<<"pivot is "<<arr[p]<<endl;
	while(i<j)
	{
		cout<<"while i and j are "<<i<<","<<j<<endl;
	   while((arr[i]<=v)&&(i<end))
	   {
			i++;
	   }	 
	   while(arr[j]>v)
	   {
			j--;
	   }	 
	   if(i<j)
	   { 
	   		cout<<"if i les j"<<endl;
			swap(arr[i], arr[j]);
	   }
	}
	swap(arr[j], arr[p]);
	printarr(arr);
	return j;
}

void quicksort(int *arr, int start, int end){
	if(end > start){
		int p = pivot(arr, start, end);
		quicksort(arr, start, p-1);		
		quicksort(arr, p+1, end);
	}
}

void quick(int *arr, int n){
	int start = 0;
	int end = n-1;
	quicksort(arr, start, end);
}

int main(){
	int a[] = {5,4,7,2,8,3,1,6}; 
	//int a[] = {39,158,98,45,67,189,7,88,29,100};
	int *arr = a;
	for(int i=0;i<8;i++){
		cout<<arr[i]<<"\t";
	}
	quick(arr,8);
	for(int i=0;i<8;i++){
		cout<<arr[i]<<"\t";
	}	
	return 0;
}

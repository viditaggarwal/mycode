#include<iostream>
using namespace std;

int pivot(int *, int, int );

void quicksort(int *a, int low, int high){
	if(low<high){
		int p = pivot(arr, low, high);
		quicksort(arr, low, p-1);
		quicksort(arr, p+1, high);		
	}
}

int pivot(int *a, int low, int high){
	int p = low;
	int fir = p;
	int sec = high;
	while(fir<high){
		if(a[p]>=a[fir]){
			fir++;
		}else{
			
		}
	}
}


int main(){
	int a[] = {5,4,7,2,8,3,1,6};
	low = 0;
	high = 7; 
	quicksort(a, low, high);
	return 0;
}

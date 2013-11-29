#include<iostream>
using namespace std;

void merge(int *, int*, int , int , int );

void printarr(int *arr){
	for(int i=0;i<8;i++){
		cout<<arr[i]<<"    ";
	}
	cout<<endl;
}

void mergesort(int *arr, int *b, int low, int high){
	int mid;
	if(low < high){
		mid = (low+high)/2;
		mergesort(arr,b, low, mid);
		mergesort(arr,b, mid+1, high);
		merge(arr,b, low, mid, high);
		printarr(arr);
	}
}

void merge(int * arr, int *b, int low, int mid, int high){
	int fir, sec,j;
	fir = low;
	sec = mid + 1;
	j = low;
 
    while((fir<=mid) && (sec<=high)){        
		if(arr[fir] <= arr[sec]){
        	b[j] = arr[fir];
        	fir++;
        }else{
        	b[j] = arr[sec];
        	sec++;
        }
        j++;
    }
    if(fir > mid){
    	for(int i=sec;i<=high;i++){
    		b[j] = arr[i];
    		j++;
    	}
    }else{
    	for(int i=fir;i<=mid;i++){
    		b[j] = arr[i];
    		j++;
    	}
    }
    for(int k=low; k<=high; k++) arr[k]=b[k];
    
}



int main(){
	int a[] = {8,4,7,2,5,3,1,6};
	int *arr = a;
	int *b = new int[8];
	mergesort(arr, b, 0, 7);		
	printarr(arr);
	return 0;
}

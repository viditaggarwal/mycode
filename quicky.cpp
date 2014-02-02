#include<iostream>
using namespace std;

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

int pivot(int *arr, int low, int high){
	cout<<"low "<<low<<" high "<<high<<endl;
	int p = low;
	int mid = (low+high)/2;
	int fir = p;
	int last = high;
	int v = arr[p];
	while(fir<last){
		while(arr[fir] <= v && (fir<high)){
			fir++;
		}
		while(arr[last] > v){
			last--;
		}
		if(fir<last){
			swap(arr[fir],arr[last]);
		}
	}
	swap(arr[last], arr[p]);
	return last;
}

void quicksort(int *arr, int low, int high){
	if(low<high){
		int p = pivot(arr, low, high);
		quicksort(arr, low, p-1);
		quicksort(arr, p+1, high);
	}
}

void print(int *arr){
	for(int i=0;i<sizeof(arr);i++){
		cout<<arr[i]<<"  ";
	}
}

int main(){
	int arr[] = {30, 10, 50, 20, 90, 15, 35, 80};
	quicksort(arr, 0, 7);
	print(arr);
	return 0;
}

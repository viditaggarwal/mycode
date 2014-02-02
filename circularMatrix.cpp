#include<iostream>
using namespace std;

void printarr(int arr[][5]){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<arr[i][j]<<"  ";
		}
		cout<<endl;
	}	
}

void circShift(int arr[][5], int n){
	cout<<arr[0][0]<<endl;
	int first, last, offset;
	for(int i=0;i<=n/2;i++){
		cout<<"firstloop"<<endl;
		first = i;
		last = n - 1 - first;
		for(int j=first;j<last;j++){
			cout<<"second loop"<<endl;
			offset = j - first;
			
			int top = arr[first][j];
			
			arr[first][j] = arr[last - offset][first];
			
			arr[last - offset][first] = arr[last][last - offset];
			
			arr[last][last - offset] = arr[j][last];
			
			arr[j][last] = top;			
		}
	}
	printarr(arr);
}

int main(){
	int arr[5][5] ={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}}; 
	printarr(arr);
	circShift(arr, 5);
	return 0;
}

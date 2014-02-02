#include<iostream>
using namespace std;
void vidit(int arr[], int n){
	for(int i=0;i<n;i++){
		arr[i] *= 2;
	}
}

int main(){
	int arr[] = {1,2,3,4,5};
	vidit(arr, 5);
	for(int i=0;i<5;i++){
		cout<<arr[i]<<endl;
	}
	return 0;
}

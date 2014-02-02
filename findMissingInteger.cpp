#include<iostream>
using namespace std;

int getLSB(int n){
	int a = n|1;
	if(a>n)return 0;
	return 1;	
}

int findMissingInteger(int *arr, int n){
	int lsb;
	int prev = getLSB(arr[0]);
	for(int i=1;i<17;i++){
		lsb = getLSB(arr[i]);
		if(prev!=lsb){
			prev = lsb;
		}else return arr[i]-1;
	}
	return 0;
}

int main(){
	int arr[] = {1,2,3,5,6,7,8,9,10,11,12,13,14,15,16,17};
	int n = 17;
	int result = findMissingInteger(arr,n);
	cout<<result<<endl;
	return 0;
}

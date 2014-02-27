#include<iostream>
using namespace std;

int computeZero(int n){
	int z = n/5;
	return z;
//	for(int i=n;i>n-5;i--){
//		if(i%5 == 0){
//			
//		}
//	}
}

int main(){
	int n = 15;
	cout<<computeZero(n);
	return 0;
}

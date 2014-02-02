#include<iostream>
#include<math.h>
using namespace std;

double calcSize(int n){
	double cnt = 0;
	while(n > 0){
		n = n/10;
		cnt++;
	}
	return cnt;	
}

int reverse(int n){
	int x;
	double sz = calcSize(n)-1;
	int number = 0;
	while(n>0){
		x = n%10;
		n = n/10;
		number += x * pow(10, sz);
		sz--;
	}
	return number;	
}

int main(){
	int n = 12345;
	cout<<reverse(n)<<endl;
	return 0;
}

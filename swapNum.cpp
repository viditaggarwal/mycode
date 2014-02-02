#include<iostream>
using namespace std;

int swapOddEvenBits(int x) {
	return ( ((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1) );
}

int main(){
	int a = 5;
	int b = 6;
	
	a = a^b;
	b = a^b;
	a = a^b;
	//cout<<a<<b<<endl;
		
	cout<<swapOddEvenBits(10)<<endl;
	return 0;
}

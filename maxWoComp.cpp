#include<iostream>
using namespace std;


int flip(int n){
	return 1^n;
}

int sign(int n){
	return flip((n>>31)&0x1);
}

int getMax(int a, int b){
	int k = sign(a-b);
	int q = flip(k);
	return k*a+q*b;
}

int getMaxOverflow(int a, int b){
	int c = a-b;
	int sa = sign(a);
	int sb = sign(b);
	int sc = sign(c);
	int sign_a = sa^sb;
	int sign_c = flip(sa^sb);
	
	int k = sign_a*sa+sign_c*sb;
	int q = flip(k);
	
	return a*k+b*q;
	
}

int main(){
	int a = -1000000000,b = 2000000000;
	cout<<getMaxOverflow(a, b);
	return 0;
}

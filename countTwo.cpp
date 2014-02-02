#include<iostream>
using namespace std;

static int sm = 0;

int calcSize(int n){
	int cnt = 0;
	while(n != 0){
		n = n/10;
		cnt++;	
	}	
	return cnt;
}

int count2sR(int n) { 
	// Base case 
	if (n == 0) return 0; 
	
	// 513 into 5 * 100 + 13. [Power = 100; First = 5; Remainder = 13] 
	int power = 1; 
	while (10 * power < n) power *= 10; 
	int first = n / power; 
	int remainder = n % power; 
	// Counts 2s from first digit 
	int nTwosFirst = 0; 
	if (first > 2) nTwosFirst += power; 
	else if (first == 2) nTwosFirst += remainder + 1; 
	
	// Count 2s from all other digits 
	int nTwosOther = first * count2sR(power - 1) + count2sR(remainder); 
	
	return nTwosFirst + nTwosOther; 
}
/*
int func(int n){
	int sz = calcSize(n);
	//int sm = 0;
	if(n == 9)return 1;
	if(n == 99)return 20;
	//while(n != 0) {
	sm += ((n/pow(10,sz-1))*func(pow(10,sz) - 1);
	n = n%(((n%pow(10,sz-1))*pow(10,sz));
	sm += func(n);
	sm += 
	//}
	return sm;
}
*/
int main(){
	//func(10000);	
	cout<<count2sR(100)<<endl;
	return 0;
}

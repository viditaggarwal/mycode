#include<iostream>
using namespace std;
int sum = 1;
void fibonacci(int a, int b, int z){
	if(sum < z){
		cout<<b<<endl;
		sum += b;
		int c = a+b;
		fibonacci(b,c,z);
	}
	return;
}

int main(){
	int a = 1;
	int b = 1;
	fibonacci(a,b,1000);
	return 0;
}

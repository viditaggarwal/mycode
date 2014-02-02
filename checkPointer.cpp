#include<iostream>
using namespace std;

int main(){
	int a = 10;
	int *b = &a;
	*b = 30;
	cout<<*b<<endl;
	cout<<a<<endl;
}

#include<iostream>
using namespace std;

int main(){
	int arr[] = {10,20,30};
	int *p = arr;
	float a = 1.1f;
	double b = 1;
	cout<<((b-a) == 0)<<endl;
	//cout<<*++p<<endl;
	return 0;
}

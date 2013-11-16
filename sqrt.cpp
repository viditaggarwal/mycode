#include<iostream>
#include<stdlib.h>
#include<iomanip>
using namespace std;

int main(){
	int n = 1000;
	double k = 1.0;
	int i=0;
	while((k*k - n) > 0.0000000001 || (n - k * k) > 0.0000000001){	
		k = (k + n / k) / 2;
		cout<<k<<endl;
		i++;
	}
	cout<<i<<endl;
	cout<<setprecision(11)<<k<<endl;
	return 0;
}

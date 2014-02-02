#include<iostream>
using namespace std;

int main(){
	int n = 1024;
	int m = 19;
	int j = 6;
	int i = 2;
	
	int allones = ~0;
	
	int left = allones<<(j+1);
	int right = ((1<<i)-1);
	
	int mask = left|right;
	int n_shift = n&mask;
	int m_shift = m<<i;
	int res = (n_shift|m_shift); 
	cout<<res<<endl;
	return 0;
}

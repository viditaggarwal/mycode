#include<iostream>
#include<map>
using namespace std;

int addSteps(int n, map<int,int> mp){
	if(n<0)return 0;
	if(n==0)return 1;
	if(mp[n]!=0){
		return mp[n];
	}else{
		mp[n] = addSteps(n-1, mp)+addSteps(n-2, mp)+addSteps(n-3, mp);
		return mp[n];
	}
}

int main(){
	int n = 10;
	map<int,int> mp;
	cout<<addSteps(n, mp);
	return 0;
}

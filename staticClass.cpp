#include<iostream>
using namespace std;

void abc1(){
	cout<<2<<endl;
}

static void abc(){
	cout<<1<<endl;
	abc1();
}


int main(){
	abc();
	return 0;
}

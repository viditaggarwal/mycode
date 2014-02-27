#include<iostream>
using namespace std;

class A(){
	int a = 5;
	static void func(){
		foo();
	}
	
	void foo(){		
		cout<<this.a<<endl;
	}
	
}

int main(){
	A.func();
	return 0;
}

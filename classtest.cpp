#include<iostream>
#include<typeinfo>
using namespace std;

class A{
	public:
		virtual void foo(){
			cout<<"a"<<endl;
		}
};

class B: public A{
	public:
		void foo(){
			cout<<"b"<<endl;
		}
};

class D{
	public:
		void foo(){
			cout<<"d"<<endl;
		}
};

class C:public B{
	public:
		void foo(){
			cout<<"c"<<endl;
		}
};

int main(){
	//A *a = new B();
	A a;
	B b;
	a = (B)b;
	cout<<typeid(a).name()<<endl;
	a.foo();
	return 0;
}

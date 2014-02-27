#include<iostream>
using namespace std;

void fizzbuzz(int n){
	for(int i=0;i<n;i++){
		if (i%15 == 0)cout<<"buzzfizz"<<endl;
		else if (i%3 == 0)cout<<"buzz"<<endl;
		else if (i%5 == 0)cout<<"fizz"<<endl;
		else cout<<i<<endl;
	}
}

int main(){
	int n=100;
	fizzbuzz(n);
	return 0;
}

#include<iostream>
using namespace std;

void recPermute(string sofar, string rest){
	if(rest==""){
		cout<<sofar<<endl;
	}else{
		for(int i=0;i<rest.length();i++){
			string next = sofar+rest[i];
			recPermute(next, rest.substr(0,i)+rest.substr(i+1));			
		}
		
	}
	
}


int main(){
	recPermute("","abcd");	
	return 0;
}

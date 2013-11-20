#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string>
using namespace std;


int main(){
	string x;
	string ts = "timestamp:";
	string cu = "customer-id:";
	string pg = "page-id:";
	string word;
	ifstream fin("log.txt");
	try{
		if(fin.is_open()){
			while(fin.good()){
				fin>>x;
				word = x.find_first_not_of()
				cout<<word<<endl;
				//cout<<x.find(cu)<<endl;
				//cout<<x.substr(10,x.find(cu))<<endl;
				//cout<<x.substr(x.find(cu),x.find(pg))<<endl;
				//cout<<x.substr(x.find(pg), x.length())<<endl;
			}
		}
	}catch(exception e){
		cout<<"error"<<endl;
	}
	
	return 0;
}

#include<iostream>
#include<string>
using namespace std;

void permuteString(string str, string sofar){
	if(str == ""){
		cout<<sofar<<endl;
	}
	else{
		for(int i=0;i<str.size();i++){
			string next = sofar + str[i]; 
			permuteString(str.substr(0,i)+str.substr(i+1), next);
		}
	}
}

int main(){
	string str = "abcd";
	string sofar = "";
	permuteString(str, sofar);
	return 0;
}

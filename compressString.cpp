#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

string compress(string str){
	string::iterator it = str.begin();
	char ch = *it;
	int cnt = 0;
	char *num;
	string newStr = "";
	for(it = str.begin(); it != str.end(); ++it) {
		cout<<*it<<endl;
		if(ch == *it){
			cnt++;
		}else{
			newStr += ch;
			itoa(cnt, num, 10);
			//cout<<num<<endl;
			newStr += num;
			ch = *it;
			cnt = 1;
		}
	}
	newStr += ch;
	itoa(cnt, num, 10);
	newStr += num;
	return newStr;
}

int main(){
	string str = "aabbccccaaa";	
	cout<<compress(str);
	return 0;
}

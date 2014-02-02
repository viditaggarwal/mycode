#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

bool checkUnique(string str){
	map<char, int> mp;
	for(int i=0;i<str.length();i++){
		if(!mp[str.at(i)]){
			mp[str.at(i)] = 1;
		}else
			return false;
	}
	return true;
}

bool checkUniqueNoSpace(string str){
	for(int i=0;i<str.length();i++){
		for(int j=i+1;j<str.length();j++){
			if(str.at(i) == str.at(j))return false;
		}
	}
	return true;	
}

void swap(char &a, char &b){
	a = a^b;
	b = a^b;
	a = a^b;
}

string reverse(string str){
	int i = 0;
	int j = str.length()-1;
	while(i<j){
		swap(str.at(i),str.at(j));
		i++;
		j--;
	}
	return str;
}

void sortStr(string &str){
	for(int i=0;i<str.length();i++){
		for(int j=i+1;j<str.length();j++){
			if(str.at(i)>str.at(j))swap(str.at(i),str.at(j));
		}
	}
}

bool checkPermutation(string str1, string str2){
	sortStr(str1);
	sortStr(str2);
	if(str1 == str2)return true;
	return false;	
}

int main(){
	string str1 = "dbca";
	string str2 = "acbbd";
	//cout<<checkUnique(str);
	//cout<<checkUniqueNoSpace(str);
	//cout<<reverse(str);
	cout<<checkPermutation(str1, str2);
	return 0;
}

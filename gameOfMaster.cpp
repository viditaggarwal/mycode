#include<iostream>
#include<string>
#include<map>
using namespace std;

void checkHits(char* pattern, char* guess, int n){
	int hit = 0;
	map<int,char> mp;
	for(int i=0;i<n;i++){
		mp[i] = pattern[i];
		if(pattern[i] == guess[i]){
			hit++;
		}
	}
	cout<<hit<<endl;
}

int main(){
	char *a = "rgby";
	char *b = "rggb";
	checkHits(a, b, 4);
	return 0;
}

#include<iostream>
#include<string>
using namespace std;

void addData(char* s, int n){
	int cnt = 0;
	for(int i = 0;i<n;i++){
		if(s[i] == ' '){
			cnt++;
		}
	}
	int new_len = n + 2*cnt;
	for(int i=n-1;i>=0;i--){
		if(s[i] == ' '){
			s[new_len-1] = '0';
			s[new_len-2] = '2';
			s[new_len-3] = '%';
			new_len -= 3;
		}else{
			s[new_len-1] = s[i];
			new_len -= 1;
		}
	}	
}

int main(){
	char s[] = "Mr John Smith    ";
	int n = 13;
	addData(s,n);
	cout<<s<<endl;
	return 0;
	
}

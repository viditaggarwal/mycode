#include<iostream>
#include<string>
using namespace std;
int cnt = 0;

void copyTwo(string str[]){
	int tmp = cnt;
	for(int i=0;i<=tmp;i++){
		str[++cnt] = str[i];
	}
}

bool checkStr(string str, int n){
	cout<<"checkStr "<<n<<endl;
	int checkCnt = 0;
	int check = 0;
	for(std::string::iterator it = str.begin(); it != str.end(); ++it) {
    	if(*it == '(')checkCnt++;
    	if(*it == ')')checkCnt--;
    	if(checkCnt == 0){
    		check++;
    	}
	}
	if(check == n-1){
		return false;
	}
	return true;
}

void countBrackets(int n, string str[]){
	if(n == 1){
		str[cnt] = "()";
		return;
	}
	if(n == 2){
		countBrackets(n-1, str);
		copyTwo(str);
		for(int i=0;i<=cnt/2;i++){
			str[i].insert(0,"()");
		}	
		for(int i=cnt/2+1;i<=cnt;i++){
			str[i].insert(0,"(");
			str[i].append(")");
		}			
		return;
	}
	countBrackets(n-1, str);
	copyTwo(str);
	bool flag;
	int tmp = cnt;
	for(int i = 0;i<=tmp;i++){
		flag = checkStr(str[i], n);
		if(flag){
			str[++cnt] = str[i];
			str[cnt].append("()");
		}
	}
	for(int i=0;i<=tmp/2;i++){
		str[i].insert(0,"()");
	}	
	for(int i=tmp/2+1;i<=tmp;i++){
		str[i].insert(0,"(");
		str[i].append(")");
	}	
}

int main(){
	int n = 5;
	string str[100];
	//cout<<checkStr("(())",3)<<endl;
	countBrackets(n, str);
	for(int i=0;i<=cnt;i++){
		cout<<str[i]<<endl;
	}
	cout<<cnt<<endl;
	return 0;
}

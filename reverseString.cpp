#include<iostream>
#include<string>
using namespace std;

void reverseStr(string str){
	string temp = "";
	string output = "";
	int sz = str.length()-1;
	int i = 0;
	while(i<=sz){
		if(str.at(i) == ' ' || i==sz){
			cout<<"got space"<<endl;
			if(i == sz){
				temp += str.at(i);
				output.insert(0,temp);
			}else{
				output.insert(0," "+temp);
			}
			temp = "";
		}else{
			temp +=str.at(i);
		}
		i++;
	}
	cout<<output<<endl;
}

/*void reverseS(string inpStr){
	string inpWrd;
	int age;
	string delimiters = " ";
	size_t current;
	size_t next = -1;
	do
	{
		current = next + 1;
		next = inpStr.find_first_of( delimiters, current );
		inpWrd=inpStr.substr( current, next - current ) ;
		reverse(inpWrd.begin(),inpWrd.end());
		
		cout<<inpWrd<<" ";
	}
	while (next != string::npos);
}*/

int main(){
	string s = "I am Don";
	reverseStr(s);
	//reverseS(s);
	return 0;
}

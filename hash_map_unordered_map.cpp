#include <iostream>
#include <string>
#include <map>
#include<set>
using namespace std;

int main() {
	set<int> st;
	st.insert(30);
	st.insert(40);
	st.insert(20);
	st.insert(10);
	map <int,int> mp;
	mp[1] = 10;
	mp[3] = 20;
	mp[5] = 14;
	mp[2] = 8;
	map<int, int>::iterator it;
	
	for(it=mp.begin(); it!=mp.end();it++){
		cout<<it->first<<","<<it->second<<endl;
	}
	
	set<int>::iterator it1;
	
	for(it1=st.begin(); it1!=st.end();it1++){
		cout<<*it1<<endl;
	}
	
}

#include<iostream>
#include<map>
using namespace std;

void countFrequency(ifstream file){
	string str;
	map<string, int> mp;
	int n;
	vector<string> vec;
	
	if (file.is_open()) {
		file >> n;
		for(int i=0;i<n;i++){
			file >> str;
			mp[str] = mp[str]+1;
		}
		file >> n;
	}
	map<string, int>::iterator *it;
	for(it = mp.begin(); it != mp.end(); it++){
		if(it->second > 1){
			vec.push(it->first);
		}
	}
	
	for(int i=0;i<mp.size();i++){
		if(mp[i])
	}
}

int main(){
	ifstream myReadFile;
 	myReadFile.open("text.txt");
 	countFrequency(myReadFile);
	return 0;
}

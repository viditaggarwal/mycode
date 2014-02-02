#include<iostream>
#include<map>
using namespace std;

int countPath(int startx, int starty, int endx, int endy){
	if(startx == endx && starty == endy){
		cout<<"found"<<endl;
		return 1;
	}
	if(startx == endx && starty != endy){
		return countPath(startx, starty+1, endx, endy);
	}
	if(startx != endx && starty == endy){
		return countPath(startx+1, starty, endx, endy);
	}
	return countPath(startx+1, starty, endx, endy)+
		   countPath(startx, starty+1, endx, endy);
}

int main(){
	cout<<countPath(0,0,2,2);
	return 0;
}

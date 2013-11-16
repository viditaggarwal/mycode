#include<iostream>
#include<stdlib.h>
#include<map>
using namespace std;

bool checkSubMat(int arr[9][9],int x, int y){
	map<int, int> check1;
	int i=0,j=0;
	bool flag = false;
	while(1){
		for(i=x;i<x+3;i++){
			for(j=y;j<y+3;j++){
					check1[arr[i][j]] == 1;
			}			
		}	
		if(check1.size() == 9){
			check1.clear();
			flag = true;
		}else{
			flag= false;
			break;
		}
		if(i==9 && y < 6){
			x=0;
			y=y+3;
		}else{
			if(i<9 && y<9){
				x = x+3;
			}else break;
		}
	}
	return flag;
}


bool sudokuCheck(int arr[9][9]){
	map<int, int> check1,check2;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			check1[arr[i][j]] == 1;
			check2[arr[j][i]] == 1;
		}		
		if(check1.size() == 9 && check2.size() == 9){
			check1.clear();
			check2.clear();
			continue;
		}
		else{
			check1.clear();
			check2.clear();	
			return false;
		}
	}
	
	return true && checkSubMat(arr,0,0);
	
}



int main(){
	int arr[9][9]={
	{ 2, 8, 4, 5, 9, 3, 1, 6, 7 },
	{ 3, 6, 9, 4, 7, 1, 8, 2, 5 },
	{ 1, 5, 7, 8, 2, 6, 4, 9, 3 },
	{ 5, 7, 6, 9, 4, 8, 2, 1, 3 },
	{ 8, 9, 2, 1, 3, 5, 6, 7, 4 },
	{ 4, 1, 3, 2, 6, 7, 9, 5, 8 },
	{ 7, 2, 1, 3, 8, 9, 5, 4, 6 },
	{ 6, 4, 5, 7, 1, 2, 3, 8, 9 },
	{ 9, 1, 8, 6, 5, 4, 7, 3, 2 } };
	cout<<sudokuCheck(arr);
	system("pause");
	return 0;
}

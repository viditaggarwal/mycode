#include<iostream>
using namespace std;

void func(int **arr){
	cout<<**arr<<endl;
}

int main(){
	int arr[][2] = {{1,3}, {5,7}};
	int **arrayv = new int[2][2];
	func(arrayv);
	
	return 0;
}

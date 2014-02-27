#include<iostream>
using namespace std;
const int sz = 4;
void rotate(int arr[sz][sz]){
	int start = 0;
	int end = sz-1;
	int offset;
	for(int k=start;k<sz/2;k++){
		end = end - k;
		offset = 0; 
		start = k;
		for(int i=k;i<end;i++){
			int temp = arr[start][i];
			arr[start][i] = arr[end-offset][start];
			arr[end-offset][start] = arr[end][end-offset];
			arr[end][end-offset] = arr[i][end];
			arr[i][end] = temp;
			offset++;
		}
	}
}

void printMat(int arr[sz][sz]){
	for(int i=0;i<sz;i++){
		for(int j=0;j<sz;j++){
			cout<<arr[i][j]<<"  ";
		}
		cout<<endl;
	}
}

int main(){
	int mat[sz][sz] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	//int mat[sz][sz] = {{1,2,3},{5,6,7},{9,10,11}};
	rotate(mat);
	printMat(mat);
	return 0;
}

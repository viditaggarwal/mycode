#include <iostream>
#include <stdlib.h>
using namespace std;

struct circarr{
	int arr[50];
	int index;
	int sz;
};

void insert(circarr *a, int n){
	if(a->index < a->sz){
		a->arr[a->index++] = n;
	}else{
		if(a->index == a->sz){
			a->index = 0;
			a->arr[a->index++]=n;
		}
	}	
}

void print(circarr *a){
	for(int i=0; i < a->sz; i++){
		cout<<a->arr[i]<<endl;
	}
}

bool binsearch(circarr *a, int n, int start, int end){
	int mid = (start + end) /2;
	if(end > start){	
		if(a->arr[mid] == n)return true;
		else{		
			if(n < a->arr[mid]){
				if(n < a->arr[start])return binsearch(a,n,mid+1, end);
				else{
					if(n > a->arr[start])return binsearch(a,n,start,mid-1);
					else{
						if(a->arr[start] == n)return true;
					}
				}
			}else{
				if(n > a->arr[mid]){
					if(n > a->arr[end])return binsearch(a,n,start, mid-1);
					else{
						if(n < a->arr[end])return binsearch(a,n,mid+1,end);
						else{
							if(a->arr[end] == n)return true;
						}
					}
				}
			}
		}
		return false;
	}
}

int main(){
	circarr *a = new circarr;
	a->sz = 5;
	a->index = 0;
	insert(a,10);	
	insert(a,20);
	insert(a,30);
	insert(a,40);
	insert(a,50);
	insert(a,60);
	insert(a,70);
	print(a);
	cout<<binsearch(a,15,0,a->sz-1)<<endl;
	system("pause");
	return 0;
}

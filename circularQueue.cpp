#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class circQueue{
	string *arr;
	int sz;
	int front, back;
	public:
		circQueue(int n){
			sz = n;
			arr = new string[sz];
			front = -1;
			back = -1;
		}
		
		void insert(string str){
			if(front == -1 && back == -1){
				arr[++back] = str;
				++front;
			}
			else{
				if(front == 0 && back ==0){
					arr[++back] = str;
				}else{
					if(front < back && back < sz-1 ){
						arr[++back] = str;
					}else{
						if(front < back && back == sz-1){
							back = 0;
							front++;
							arr[back] = str;
						}else{
							if(front > back && back < sz-1){
								if(front != back+1)arr[++back] = str;
								else{
									arr[++back] = str;
									front++;
								}
							}else{
								if(front > back && back == sz-1){
									back = 0;
									arr[back] = str;
								}
							}
						}
					}
				}
			}
		}
		
		void print(){
			if(front<=back){
				for(int i=front;i<=back;i++){
					cout<<arr[i]<<endl;
				}
			}else{
				for(int i=front;i<sz;i++)cout<<arr[i]<<endl;
				for(int i=0;i<=back;i++)cout<<arr[i]<<endl;
			}
		}
		
		void remove(int n){
			while(n>0){
				if(front == back){
					front = -1;
					back = -1;
				}else{
					if(front >= 0 && front < sz-1)front++;				
					else if(front == sz-1) front = 0;
				}
				n--;
			}
		}	
};

int main(){
	int n;
	char opr;
	int x;
	string str;
	cout<<"Enter the size"<<endl;
	cin>>n;
	circQueue *q = new circQueue(n);
	while(1){
		cout<<"Enter the option"<<endl;
		cin>>opr;
		switch(opr){
			case 'A': {
				cin>>x;
				for(int i=0;i<x;i++){
					cin>>str;
					q->insert(str);	
				}			
				break;
			}
			
			case 'R': {
				cin>>x;
				q->remove(x);	
				break;
			}
			case 'L': {
				q->print();
				break;
			}
			
			case 'Q': exit;
		}	
	}
	return 0;
}

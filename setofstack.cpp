#include<iostream>
#include<stack>
using namespace std;

class setOfStack{
	private:
		stack<int> sos[10];
		int stck = 0;
		int top = -1;
		int th = 3;
	public:
		void push(int n){
			if(top<th){
				top++;	
			}else{
				top = -1;
				stck++;
				top++;
			}
			sos[stck].push(n);						
		}
		
		int pop(){
			int val = sos[stck].top();
			sos[stck].pop();
			top--;
			if(top == -1){
				top = th-1;
				stck--;
			}	
			return val;		
		}			
		void printsos(){
			int prstck = stck;
			int prtop = top;
			stack<int> dump[10] = sos;
			while(prstck!=-1){
				if(prtop > -1){
					cout<<dump[prstck].top()<<endl;
					dump[prstck].pop();
					prtop--;	
				}else{
					prtop = th;
					prstck--;
					cout<<dump[prstck].top()<<endl;
					dump[prstck].pop();
					prtop--;
				}
			}
		}
};


int main(){
	setOfStack *s = new setOfStack();	
	s->push(10);	
	s->push(20);
	s->push(30);
	s->push(40);
	s->push(50);
	s->push(60);
	s->push(70);
	s->printsos();
	return 0;
}


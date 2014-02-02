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
			if(top<th-1){
				top++;
			}else{
				stck++;
				top = -1;
				top++;
			}
			sos[stck].push(n);						
		}
		
		int pop(){
			int val = sos[stck].top();
			sos[stck].pop();
			top--;			
			if(top == -1){
				stck--;
				top = th-1;				
			}	
			return val;		
		}
		
		int getStckSize(){
			return stck+1;
		}
		
		void leftShift(int stk){
			int tempTop;
			int copyTop = top;
			int val;
			if(stk < stck){
				stack<int> tmp;
				tempTop = -1;
				if(stk+1 != stck){
					while(tempTop<th-1){
						cout<<"tempTop"<<endl;
						val = sos[stk+1].top();
						if(tempTop < th-2){
							cout<<"push"<<endl;
							tmp.push(val);
						}
						tempTop++;
						sos[stk+1].pop();
					}
				}else{
					while(tempTop<copyTop){
						cout<<"tempTop"<<endl;
						val = sos[stk+1].top();
						if(tempTop < copyTop-1){
							cout<<"push"<<endl;
							tmp.push(val);
						}
						tempTop++;
						sos[stk+1].pop();
					}
				}
				sos[stk].push(val);
				tempTop = -1;
				cout<<"before transfer"<<endl;
				while(tempTop < copyTop - 1){
					sos[stk+1].push(tmp.top());
					tmp.pop();
					tempTop++;
				}
				leftShift(stk+1);
			}			
		}
		
		int pop(int stk){
			int rem;
			if(top < th){
				if(stk == stck){
					rem = sos[stk].top();
					sos[stk].pop();
					if(top == 0){
						top--;
						stck--;
					}else{
						top--;	
					}					
				}else{
					rem = sos[stk].top();
					sos[stk].pop();
					cout<<"left shift"<<endl;
					leftShift(stk);
					top--;
				} 
			}
			return rem;
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
					if(prstck != 0){
						prtop = th-1;
						prstck--;
						cout<<dump[prstck].top()<<endl;
						dump[prstck].pop();
						prtop--;
					}else break;
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
	s->push(40);
	s->push(50);
	s->push(60);
	s->push(70);
	s->pop(2);	
	cout<<s->getStckSize()<<endl;
	s->printsos();
	return 0;
}


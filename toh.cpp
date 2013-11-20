#include<iostream>
#include<stack>
using namespace std;

class toh{
	private:
		int *d;
		int N;
		stack<int> rod[3];
	public:
		toh(int disks){
			N=disks;
			for(int i=N-1;i>=0;i--){
				rod[0].push(i);
			}
		}
		
		void moveTower(int n, int src, int dst, int tmp){
			if(n==0){
				moveSingleDisk(src, dst);
			}
			else{
				moveTower(n-1, src, tmp, dst);
				moveSingleDisk(src, dst);			
				moveTower(n-1, tmp, dst, src);	
			}			
		}
		
		void moveSingleDisk(int src, int dst){
			if(rod[src].size()>0){
				rod[dst].push(rod[src].top());
				rod[src].pop();		
			}
		}
		
		
		void printStatus(){
			cout<<rod[0].size()<<"\t"<<rod[1].size()<<"\t"<<rod[2].size()<<endl;			
		}
	
};

int main(){
	toh *t = new toh(5);
	t->printStatus();
	t->moveTower(5,0,2,1);
	t->printStatus();
	return 0;
}

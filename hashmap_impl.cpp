#include<iostream>
#include<list>
using namespace std;

class hash{
	class Node{
		public:
		int key;
		int value;
	};
	
	list<Node> *buckets;
	int bucketsSize = 10;
	public:
		hash(){
			buckets = new list<Node>[bucketsSize];
			for(int i=0;i<bucketsSize;i++){
				list<Node> lst;
				buckets[i] = lst;
			}
		}
		
		int hashFunction(int Key){
			while(1){
				if(Key/10 != 0)
					Key = Key / 10;
				else
					break;		
			}
			return Key;
		}
		
		void insert(int Key, int Value){
			Node nn;
			nn.key = Key;
			nn.value = Value;
			int hashKey = hashFunction(Key);
			list<Node> lst = buckets[hashKey];
			lst.push_back(nn);
			buckets[hashKey] = lst;
		} 
		
		int getValue(int Key){
			list<Node> lst = buckets[hashFunction(Key)];	
			list<Node>::iterator it;
			int cnt = 0;
			for(it = lst.begin(); it!= lst.end();it++){
				Node nn = *it;
				if(nn.key == Key)return nn.value;
			}
			return -1;
		}
};



int main(){
	hash *h = new hash();
	h->insert(10,20);
	h->insert(100,200);
	cout<<h->getValue(100);
	return 0;
}

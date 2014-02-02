#include<iostream>
#include<string>
using namespace std;

class node{
	public:
	bool is_end;
	int prefix_count;
	char str;
	node *child[26];
	node()
    {
        prefix_count=0;
        is_end=0;
        for(int i=0;i<26;i++)
           child[i]=NULL;
    }
	
	node(char s)
    {
        prefix_count=0;
        is_end=0;
        str = s;
		for(int i=0;i<26;i++)
           child[i]=NULL;
    }
}*root;



void insert(string str){	
	node *current = root;
	for(int i=0;i<str.length();i++){
		int letter = (char)str[i] - 'a';
		if(current->child[letter] == NULL)
			current->child[letter] = new node((char)str[i]);
		current = current->child[letter];				
	}	
	current->is_end++;
}

bool search(string str){
	node *current = root;
	for(int i=0;i<str.length();i++){
		int letter = (char)str[i] - 'a';
		if(current->child[letter] == NULL)
			return false;
		current = current->child[letter];
	}
	if(current->is_end)return true;
	else return false;	
}

int main(){
	root = new node();
	insert("hello");
	cout<<search("hello");
	return 0;
}

#include<iostream>
#include<string.h>
using namespace std;

class node
{
public:
      int prefix_count;
      int is_end;
      node *child[26];
      /*node()
      {
            prefix_count=0;
            is_end=0;
            for(int i=0;i<26;i++)
                  child[i]=NULL;
      }*/

}*head;

void insert(char *word){
	int len = strlen(word);
	node *current = head;
	current->prefix_count++;
	for(int i=0; i<len; i++){
		int letter = word[i] - (int)'a';
		if(current->child[letter] == NULL)
			current->child[letter] = new node();
		current->child[letter]->prefix_count++;
		current = current->child[letter];				
	}
	current->is_end = 1;
}

void search(char *word){
	int len = strlen(word);
	node *current = head;
	for(int i=0; i<len; i++){
		int letter = word[i] - (int)'a';
		if(current->child[letter] != NULL){
			current = current->child[letter];
		}else{
			cout<<"not found"<<endl;
			return;
		}		
	}
	if(current->is_end == 1){
		cout<<"found"<<endl;
	}
}

int main(){
	head = new node();
	insert("hello");
	insert("hilalo");
	search("helpo");
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define um unordered_map<char,node*>

class node{
public:
	char data;
	um m;
	bool isTerminal;
		
	node(char d){
		
		data=d;	
		isTerminal=false;
	}
	
};

class Trie{
	
	node* root;
	public:
		Trie(){
			root=new node('\0');
		}
		
		void addWord(char *word){
			
			node* temp=root;
			for(int i=0;word[i]!='\0';i++){
				char ch=word[i];
				
				//if ch is present
				if(temp->m.count(ch)){
					temp=temp->m[ch];
				}
				
				else{
					node* n=new node(ch);
					temp->m[ch]=n;
					temp=n;
				}
				
			}
			temp->isTerminal=true;
			return;
			
		}
		
		bool search(char * word){
			
			node* temp=root;
			for(int i=0;word[i]!='\0';i++){
			
				char ch=word[i];

				if(temp->m.count(ch)==0){
					return false;
				}else{
					temp=temp->m[ch];
				}
			
			}
			//check if the ending char is terminal or not
			return temp->isTerminal;
			
		}
	
};

int main(){

	Trie t;
	char words[][100]={"apple","apen","no","not","news"};
	
	for(int i=0;i<5;i++){
		t.addWord(words[i]);
	}
	
	char s[100];
	cin>>s;
	if(t.search(s)){
		cout<<"Found";
	}else cout<<"not found";
	
	
	return 0;
}

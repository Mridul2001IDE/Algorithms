//reverse stack recurrsively
#include<iostream>
#include "Stack.h"

using namespace std;

void pushAtBottom(Stack<int>&s,int no){
	
	//base case
	if(s.size()==0){
		s.push(no);
		return;
	}
	
	//otherwise
	int t=s.top();
	s.pop();
	pushAtBottom(s,no);
	s.push(t);
	
}

void reverse(Stack<int>&s){
	
	//base case
	if(s.size()==0) return;
	
	//Normal case
	int top=s.top();
	s.pop();
	reverse(s);
	
	pushAtBottom(s,top);
	
}

void print(Stack<int>s){
	while(!s.isEmpty()){
		cout<<s.top()<<" ";
		s.pop();
	}cout<<"\n";
}

int main(){
	
	Stack<int> s;
	
	for(int i=0;i<6;i++)
		s.push(i);
	
	print(s);
	
	reverse(s);
	
	print(s);
	
	return 0;
}

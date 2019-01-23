//stack demo
#include<iostream>
#include "Stack.h"

using namespace std;

int main(){
	Stack<int> s;
	
	for(int i=0;i<5;i++){
		s.push(i*i);
	}
	
	while(!s.isEmpty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	
	return 0;
}

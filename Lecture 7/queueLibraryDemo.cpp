#include<iostream>
#include<queue>
#include<deque>
using namespace std;

int main(){
	//this is not a circular queue
	queue<int> q;
	for(int i=0;i<7;i++)
		q.push(i);
	
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	
	cout<<"\n";	
		
	//doubly ended queue
	//push_front,pop_front,push_back,pop_back
	
	deque<int>dq;
	for(int i=0;i<7;i++)
		dq.push_back(i);
	
	while(!dq.empty()){
		cout<<dq.front()<<" ";
		dq.pop_front();
	}	
		
	return 0;
}

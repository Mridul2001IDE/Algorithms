#include<iostream>
#include<queue>
//greater<int> is in this header file
#include<functional>
#include<cstring>
using namespace std;

class Person{
	
	public: 
		char name[100];
		int money;
		
		Person(){
		}
		
		Person(char* n,int m){
			strcpy(name,n);
			money=m;
		}
	
};

//comparator is passes as a class
// this is a Functor - class behaving as a function
class PersonCompare{
	public:
	bool operator()(const Person &p1,const Person &p2){
		return p1.money<p2.money;
	}
	
};

int main(){
	//by default max heap
	priority_queue<int>pq;
	
	//to make min heap
	//priority_queue<int,vector<int>,greater<int>> pq1;
	
	int a[]={12,7,6,8,4,9,1,2,10,15};
	
	for(int i=0;i<10;i++){
		pq.push(a[i]);
	}
	
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<"\n";
	
	//customised heap with own comparator
	priority_queue<Person,vector<Person>,PersonCompare>pp;
	Person p1("ABC",100);
	Person p2("er",10);
	Person p3("tu",2);
	
	pp.push(p1);
	pp.push(p2);
	pp.push(p3);
			
	while(!pp.empty()){
		Person p=pp.top();
		cout<<p.name<<" "<<p.money<<"\n";
		pp.pop();
	}
	
	return 0;
}

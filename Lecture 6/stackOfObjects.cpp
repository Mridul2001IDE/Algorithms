//stack of objects
#include<iostream>
#include<string.h>
#include "Stack.h"

using namespace std;

class Book{
	public:	
	int price;
	char name[20];
	
	//default constructor is necessary
	Book(){}
	
	Book(int p,char *n){
		price=p;
		strcpy(name,n);
	} 
	

	void print(){
		cout<<price<<" "<<name<<"\n";
	}
		
};

int main(){
	
	Stack<Book>sb;
	Book b1(100,"c++");
	Book b2(200,"java");
	Book b3(300,"python");
	
	sb.push(b1);
	sb.push(b2);
	sb.push(b3);
	
	while(!sb.isEmpty()){
		Book tp=sb.top();
		tp.print();
		sb.pop();
	}
	
	return 0;
}

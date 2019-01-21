//operator overloading
// overloading the << operator to print the whole linked list
#include<bits/stdc++.h>

using namespace std;

class Node{
public:	
	int data;
	Node* next;
	
	//initialisation list in the constructor
	Node (int d):data(d),next(NULL) {}
	
};

//operator overloading
void operator<<(ostream &o,Node* a){
	while(a){
		o<<a->data<<" ";
		a=a->next;
	}
}

//insert element at front of linked list
void insertAtFront(Node* &head,int d){
	
	//creating node using constructor
	Node *t=new Node(d);
	t->next=head;
	head=t;
	
}

//taking input
Node *takeInput(){
	
	Node *head=NULL;
	
	int d;
	cin>>d;
	
	while(d!=-1){
		insertAtFront(head,d);
		cin>>d;
	}
	return head;
}

int main(){
		
	Node* a=takeInput();
	cout<<a;
	
	return 0;
}

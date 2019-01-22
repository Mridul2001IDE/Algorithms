//delete entire linked list by - delete(head)

#include<bits/stdc++.h>
using namespace std;

class Node{
public:	
	int data;
	Node* next;
	
	//initialisation list in the constructor
	Node (int d):data(d),next(NULL) {}
	
	//main functionality
	~Node(){
		cout<<"Deleting Node: "<<data<<"\n";
		if(next!=NULL){
			delete next;
		}
		
	}
	
};

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

//printing the linked list
void print(Node* head){
	
	while(head){
		cout<<head->data<<"->";
		head=head->next;
	}cout<<"\n";
	
}


int main(){
	
	Node* a=takeInput();
	print(a);			
	delete a;
	return 0;

}

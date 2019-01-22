//reverse a linked list
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

//reversing the linked list iteratively
void reverseIter(Node* &head){
	Node* current=head;
	Node* prev=NULL;
	Node* Next;
	while(current!=NULL){
		
		Next=current->next;
		current->next=prev;
		prev=current;
		current=Next;
		
	}
	head=prev;
	
}

//reversing the linked list recursion
Node* reverseRecur(Node* head){
	
	if(head==NULL||head->next==NULL) return head;
	
	//recursive step
	Node* chotaHead=reverseRecur(head->next);
	Node* temp=chotaHead;
	
	while(temp->next!=NULL){
		temp=temp->next;
	}
	
	temp->next=head;
	head->next=NULL;
	return chotaHead;
	
}

//optimised implementation
Node* reverseRecur2(Node* head){
	
	if(head==NULL||head->next==NULL) return head;
	
	//recursive step
	Node* chotaHead=reverseRecur(head->next);
	
	head->next->next=head;
	head->next=NULL;
	return chotaHead;
	
}


int main(){
	
	Node* a=takeInput();
	print(a);
	reverseIter(a);			
	print(a);
	a=reverseRecur(a);
	print(a);
	a=reverseRecur2(a);
	print(a);
	return 0;

}

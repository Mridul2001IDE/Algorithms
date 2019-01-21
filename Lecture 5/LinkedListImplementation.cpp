//take input and build a linked list
#include<bits/stdc++.h>

using namespace std;

class Node{
public:	
	int data;
	Node* next;
	
	//initialisation list in the constructor
	Node (int d):data(d),next(NULL) {}
	
};

//insert element at front of linked list
void insertAtFront(Node* &head,int d){
	
	//creating node using constructor
	Node *t=new Node(d);
	t->next=head;
	head=t;
	
}

//adding in middle
void addInMiddle(Node* &head,int data,int pos){
	
	if(pos==0){
		
		insertAtFront(head,data);
		return;
		
	}else{
		
		//p is less than the length
		int jump=1;
		Node* temp=head;
		while(jump<=pos-1){
			temp=temp->next;
			jump++;
		}
		
		Node* n=new Node(data);
		n->next=temp->next;
		temp->next=n;
		return;
		
	}
	
}

//deleting from the start
void deleteFront(Node* &head){
	
	Node* temp=head->next;
	delete(head);
	head=temp;
	
}

//length of linked list
int length(Node* head){
	int len=0;
	while(head!=NULL){
		len++;
		head=head->next;
	}
	return len;
}

//searching for a element - Linear Search Recursive
Node* searchElement(Node *head,int element){
	
	if(head==NULL) return NULL;
	
	if(head->data==element) return head;
	
	else searchElement(head->next,element);
	
}

//find midPoint of a LinkedList
Node* midPoint(Node* head){
	
	Node* slow=head;
	Node* fast=head->next;
	
	while(fast&&fast->next){
		
		fast=fast->next->next;
		slow=slow->next;
		
	}
	
	return slow;
	
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
		
	Node* head=takeInput();
	Node* tail=NULL;
	print(head);	
	
	addInMiddle(head,4,3);
	print(head);
	deleteFront(head);
	print(head);
	
	return 0;
}

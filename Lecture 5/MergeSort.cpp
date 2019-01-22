//MergeSort

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

//length of linked list
int length(Node* head){
	int len=0;
	while(head!=NULL){
		len++;
		head=head->next;
	}
	return len;
}

//merge
Node* merge(Node* a,Node* b){
	
	//base case
	if(a==NULL){
		return b;
	}
	else if(b==NULL){
		return a;
	}
	
	//otherwise
	Node* nh;
	if(a->data<b->data){
		nh=a;
		a->next=merge(a->next,b);
	}else {
		nh=b;
		b->next=merge(a,b->next);
	}
	
	return nh;
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

//mergeSort
Node* mergeSort(Node* l){
	
	//base case
	if(l==NULL||l->next==NULL){
		return l;
	}
	
	//recursive case
	Node* mid=midPoint(l);
	Node* a=l;
	Node* b=mid->next;
	mid->next=NULL;
	
	a=mergeSort(a);
	b=mergeSort(b);
	
	return merge(a,b);
}

//overloading the >> operator
istream& operator>>(istream& is,Node* &a){
	
	a=takeInput();
	return is;
	
}

int main(){
		
	Node* a;
	
	cin>>a;
	
	cout<<"Sorted: ";
	print(mergeSort(a));
	
	return 0;
}

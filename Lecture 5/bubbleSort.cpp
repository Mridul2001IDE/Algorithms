//bubble sort in linked list
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

//bubble sort
void bubbleSort(Node* &head){
	
	int n=length(head);
	
	for(int i=0;i<n-1;i++){
		
		//pairwise swapping
		Node*current=head;
		Node*prev=NULL;
		
		//since the inner for loop in bubble sort goes upto n-2
		while(current!=NULL&&current->next!=NULL){
			
			if(current->data > current->next->data){
				
				//swapping
				//starting 2 nodes
				if(prev==NULL){
					Node* nextNode=current->next;
					current->next=nextNode->next;
					nextNode->next=current;
					head=nextNode;
					prev=nextNode;
				}else{
					//2 nodes in middle
					Node* nextNode=current->next;
					current->next=nextNode->next;
					nextNode->next=current;
					prev->next=nextNode;
					prev=nextNode;
				}
				
			}else{
				
				prev=current;
				current=current->next;
				
			}
			
		}
		
	}
	
}

int main(){
		
	Node* head=takeInput();
	Node* tail=NULL;
	print(head);	
	bubbleSort(head);
	print(head);
	return 0;
}

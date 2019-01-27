//convert bst to sorted linked list
#include<iostream>

using namespace std;

class node{
public:	
	int data;
	node* left;
	node* right;
	
	//initialisation list - constructor
	node(int d):data(d),left(NULL),right(NULL){}
	
};

node* insertInBST(node* root,int data){
	if(root==NULL){
		root=new node(data);
		return root;
	}else{
		if(data<root->data){
			root->left=insertInBST(root->left,data);
		}
		
		else{
			root->right=insertInBST(root->right,data);
		}
	}
	return root;
}

node* takeInput(){
	//if input is -1 that means node does not exist
	node *root=NULL;
	int data;
	cin>>data;
	
	while(data!=-1){
		root=insertInBST(root,data);
		cin>>data;
	}
	return root;
	
}

//implementing own customised linked list class
class LL{
public:	
	node* head;
	node* tail;
	
};

// func to convert to linked list
LL tree2LL(node* root){
	
	LL l;
	
	if(root==NULL){
		l.head=NULL;
		l.tail=NULL;
		return l;
	}
	else if(root->left==NULL&&root->right==NULL){
		l.head=root;
		l.tail=root;
		return l;
	}
	else if(root->left!=NULL&&root->right==NULL){
		LL leftLL=tree2LL(root->left);
		leftLL.tail->right=root;
		l.tail=root;
		l.head=leftLL.head;
	}
	else if(root->left==NULL&&root->right!=NULL){
		LL rightLL=tree2LL(root->right);
		root->right=rightLL.head;
		l.head=root;
		l.tail=rightLL.tail;	
	}else{
		
		LL leftLL=tree2LL(root->left);
		LL rightLL=tree2LL(root->right);
		
		leftLL.tail->right=root;
		root->right=rightLL.head;
		l.head=leftLL.head;
		l.tail=rightLL.tail;
		
		return l;
	}
	
	
}


istream& operator>>(istream& is,node* &root){
	root=takeInput();
	return is;
}


int main(){
	node* root=NULL;
	cin>>root;
	
	LL myList=tree2LL(root);
	
	node* temp=myList.head;
	
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->right;
	}
	
	return 0;
}

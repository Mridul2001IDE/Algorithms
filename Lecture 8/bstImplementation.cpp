//binary search tree
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

node* search(node* root,int key){
	
	if(root==NULL){
		return NULL;
	}else if(root->data==key){
		return root;
	}
	
	else if(root->data>key){
		return search(root->left,key);
	}else{
		return search(root->right,key);
	}
	
}

//like preorder
void printTree(node* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" = ";
	if(root->left) cout<<root->left->data<<",";
	if(root->right) cout<<root->right->data;
	cout<<"\n";
	
	printTree(root->left);
	printTree(root->right);
	
}

istream& operator>>(istream& is,node* &root){
	root=takeInput();
	return is;
}

ostream& operator<<(ostream& os,node* root){
	printTree(root);
	return os;
}

int main(){
	int key;
	node* root=NULL;
	cin>>root;
	cout<<root<<"\n";
	cout<<"\nEnter element to search: ";
	cin>>key;
	cout<<search(root,key)->data;
	
	return 0;
}

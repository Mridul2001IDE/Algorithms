//deletion in bst
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

node* findMin(node* root){
	
	while(root->left!=NULL){
		root=root->left;
	}
	return root;
}

//deletion
node* deleteNode(node* root,int data){
	
	if(root==NULL){
		return root;
	}
	
	//otherwise
	if(root->data==data){
		//3 cases
		
		//1. leaf node	
		if(root->left==NULL&&root->right==NULL){
			delete root;
			root=NULL;
			return root;
		}
		
		//2. one child
		if(root->left!=NULL&&root->right==NULL){
			
			node* temp=root->left;
			delete root;
			return temp;
			
		}
		if(root->right!=NULL&&root->left==NULL){
			
			node* temp=root->right;
			delete root;
			return temp;
			
		}
		
		//3. two child of root
		if(root->right!=NULL&&root->left!=NULL){
			//replacing with the min element of right subtree
			node* temp=findMin(root->right);
			root->data=temp->data;
			root->right=deleteNode(root->right,temp->data);
			return root;
		}
		
	}
	
	else if(root->data>data){
		root->left=deleteNode(root->left,data);
	}
	else{
		root->right=deleteNode(root->right,data);
	}
	return root;
	
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
	cout<<"Enter element to be deleted: ";
	cin>>key;
	root=deleteNode(root,key);
	cout<<root;
	return 0;
}

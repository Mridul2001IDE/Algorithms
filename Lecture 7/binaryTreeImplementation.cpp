//binary tree implementation
// preorder,postorder,inorder transversals
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

node* takeInput(){
	//if input is -1 that means node does not exist
	int data;
	cin>>data;
	
	node* n=NULL;
	if(data!=-1){
		n=new node(data);
		n->left=takeInput();
		n->right=takeInput();
	}
	return n;
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

//3 type of transversing tree

//preorder - root,left,right
void preOrder(node* root){
	if(root==NULL) return;
		
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

//inorder - left,root,right
void inOrder(node* root){
	if(root==NULL) return;
	
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);

}

//postorder - left,right,root
void postOrder(node* root){
	if(root==NULL) return;

	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
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
	
	node* root=NULL;
	cin>>root;
	cout<<root<<"\n";
	
	preOrder(root);
	cout<<"\n";
	inOrder(root);
	cout<<"\n";
	postOrder(root);
	
	
	return 0;
}

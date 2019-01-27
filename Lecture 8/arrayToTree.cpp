//convert sorted array to balanced bst
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

node* arrayToTree(int a[],int s,int e){
	
	if(s>e){
		return NULL;
	}
	
	int mid=(s+e)/2;
	node* root=new node(a[mid]);
	root->left=arrayToTree(a,s,mid-1);
	root->right=arrayToTree(a,mid+1,e);
	
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

ostream& operator<<(ostream& os,node* root){
	printTree(root);
	return os;
}


int main(){
	
	int a[]={1,2,3,4,5,6,7};
	
	node* root=arrayToTree(a,0,8);
	cout<<root;	
	return 0;
}

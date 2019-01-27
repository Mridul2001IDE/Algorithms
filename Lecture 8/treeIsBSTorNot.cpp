//check is a binary tree is a bst or not

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

//check if binary tree is bst or not
bool isBST(node* root,int minV=INT_MIN,int maxV=INT_MAX){
	
	if(root==NULL){
		return true;
	}
	
	if(root->data>minV&&root->data<maxV && isBST(root->left,minV,root->data) && isBST(root->right,root->data,maxV)){
		return true;
	}
	return false;
	
}


int main(){
	
	int a[]={1,2,3,4,5,6,7,8,9};
	
	node* root=arrayToTree(a,0,10);
	
	if(isBST(root)){
		cout<<"BST hai!";
	}else cout<<"BST ni hai!";
	
	return 0;
}

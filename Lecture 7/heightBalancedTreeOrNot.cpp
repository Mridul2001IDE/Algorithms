//tree is height balanced or not
#include<bits/stdc++.h>
#include<queue>

using namespace std;

class node{
public:	
	int data;
	node* left;
	node* right;
	
	//initialisation list - constructor
	node(int d):data(d),left(NULL),right(NULL){}
	
};

//taking input level by level
void levelOrderBuild(node*&root){

	cout<<"Enter Root Data - "<<endl;
	int d;
	cin>>d;

	root  = new node(d);
	queue<node*> q;
	q.push(root);

	while(!q.empty()){
		node* n = q.front();
		q.pop();

		int c1,c2;
		cout<<"Enter children of "<<n->data<<endl;
		cin>>c1>>c2;
		if(c1!=-1){
			n->left = new node(c1);
			q.push(n->left);
		}
		if(c2!=-1){
			n->right = new node(c2);
			q.push(n->right);
		}
	}
}

pair<int,bool> isBalanced(node* root){
	
	if(root==NULL){
		return make_pair(0,true);
	}
	
	pair<int,bool> left=isBalanced(root->left);
	pair<int,bool> right=isBalanced(root->right);
	
	int height=max(left.first,right.first)+1;
	
	if(abs(left.first-right.first)<=1 && left.second && right.second){
		return make_pair(height,true);
	}else{
		return make_pair(height,false);
	}
	
}

int main(){
	
	node* root=NULL;
	levelOrderBuild(root);
	cout<<isBalanced(root).first<<" "<<isBalanced(root).second;
	return 0;
}

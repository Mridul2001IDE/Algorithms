//max sum of subtree s.t you can select a node or its immediate parent or child
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

//maxSum
pair<int,int> maxSum(node* root){
	
	if(root==NULL){
		return make_pair(0,0);
	}
	
	pair<int,int> left=maxSum(root->left);
	pair<int,int> right=maxSum(root->right);
	
	int inc=root->data+left.second+right.second;
	int exc=max(left.first,left.second)+max(right.first,right.second);
	
	return make_pair(inc,exc);
	
}

int main(){
	
	node* root=NULL;
	levelOrderBuild(root);
	pair<int,int>p=maxSum(root);
	cout<<max(p.first,p.second);
	return 0;
}

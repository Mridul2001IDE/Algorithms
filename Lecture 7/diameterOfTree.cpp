//diameter of tree - longest distance between any 2 nodes
#include<iostream>
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

class Pair{
	public:
		int height;
		int diameter;
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

//height of tree
int height(node* root){
	if(root==NULL) return 0;
	
	return 1+max(height(root->left),height(root->right));
}

int diameter(node* root){
	
	if(root==NULL) return 0;
	
	//diameter passes thourgh root
	int op1=height(root->left)+height(root->right);
	
	//diameter lies in left subtree
	int op2=diameter(root->left);
	
	//diameter lies in left subtree
	int op3=diameter(root->right);
	
	return max(op1,max(op2,op3));
}


//optimising the above function by building bottom up
Pair fastDiameter(node* root){
	Pair p;
	
	if(root==NULL){
		p.height=0;
		p.diameter=0;
		return p;
	}
	
	//postorder
	
	Pair left=fastDiameter(root->left);
	Pair right=fastDiameter(root->right);
	
	int op1=left.height+right.height;
	int op2=left.diameter;
	int op3=right.diameter;
	
	p.diameter=max(op1,max(op2,op3));
	p.height=1+max(left.height,right.height);
	
	return p;
}


int main(){
	
	node* root=NULL;
	levelOrderBuild(root);
	cout<<diameter(root)<<" ";
	Pair p=fastDiameter(root);
	cout<<p.diameter;
	return 0;
}

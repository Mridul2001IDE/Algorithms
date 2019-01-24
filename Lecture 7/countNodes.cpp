//count nodes in tree , heigth of tree
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

//count no of nodes
int countNode(node* root){
	if(root==NULL) return 0;
	
	return 1+countNode(root->left)+countNode(root->right);
}

//height of tree
int height(node* root){
	if(root==NULL) return 0;
	
	return 1+max(height(root->left),height(root->right));
}

int main(){
	
	node* root=NULL;
	levelOrderBuild(root);
	cout<<countNode(root)<<" "<<height(root);
	
	return 0;
}

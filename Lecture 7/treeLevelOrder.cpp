//breadth first transversal
//taking tree input and output level by level
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

//printing tree level by level
void levelOrderPrint(node* root){
	queue<node*>q;
	q.push(root);
	q.push(NULL);
	 
	while(!q.empty()){
		node* f=q.front();
		q.pop();
		if(f==NULL){
			cout<<endl;
			if(!q.empty()){
				q.push(NULL); 
			}
		}else{
		
		cout<<f->data<<" ";
		if(f->left){
			q.push(f->left);
		}
		if(f->right){
			q.push(f->right);
		}
	}
	}
	
	return;	
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
	
	node* root=NULL;
	levelOrderBuild(root);
	levelOrderPrint(root);
	
	return 0;
}

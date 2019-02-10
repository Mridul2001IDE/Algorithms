//segment tree - range min ques
#include<iostream>
using namespace std;

//O(n) time
//index is the pos in the tree array , s and e are the range
void buildTree(int *tree,int *a,int index,int s,int e){
	
	//base case
	if(s>e){
		return;
	}
	
	//leaf node
	if(s==e){
		tree[index]=a[s];
		return;
	}
	
	//recursive case
	int mid=(s+e)/2;
	//build left subtree
	buildTree(tree,a,2*index,s,mid);
	//build right subtree
	buildTree(tree,a,2*index+1,mid+1,e); 
	
	int left=tree[2*index];
	int right=tree[2*index+1];
	
	tree[index]=min(left,right);
	
}

// s and e for the tree , return min element lying in the range qs and qe
int query(int *tree,int index,int s,int e,int qs,int qe){
	
	//3 cases
	
	//no overlap
	if(qs>e || qe<s){
		return INT_MAX;
	}
	
	//complete overlap
	if(s>=qs && e<=qe){
		return tree[index];
	}
	
	//partial overlap - call both sides
	int mid=(s+e)/2;
	int leftAns=query(tree,2*index,s,mid,qs,qe);
	int rightAns=query(tree,2*index+1,mid+1,e,qs,qe);
	return min(leftAns,rightAns);
	
}

//node update
//logN time
void updateNode(int *tree,int index,int s,int e,int i,int value){
	
	//no overlap
	if(i<s||i>e){
		return;
	}
	
	//reached leaf node
	if(s==e){
		tree[index]=value;
		return;
	}
	
	//partial overlap - i is lying in range between s and e
	int mid=(s+e)/2;
	updateNode(tree,2*index,s,mid,i,value);
	updateNode(tree,2*index+1,mid+1,e,i,value);
	//upr ke nodes bhi to update krne pdenge min of child se
	tree[index]=min(tree[2*index],tree[2*index+1]);
	return;

}

//range update - O(n)
//given rs ans re - increment every value in the range by a value inc
void rangeUpdate(int *tree,int index,int s,int e,int rs,int re,int inc){
	
	//no overlap
	if(re<s||rs>e){
		return;
	}
	
	//reached leaf node
	if(s==e){
		tree[index]+=inc;
		return;
	}
	
	//lying in range - call both sides
	int mid=(s+e)/2;
	rangeUpdate(tree,2*index,s,mid,rs,re,inc);
	rangeUpdate(tree,2*index+1,mid+1,e,rs,re,inc);
	//upr ke nodes bhi to update krne pdenge min of child se
	tree[index]=min(tree[2*index],tree[2*index+1]);
	return;
	
}

int main(){
	int a[]={1,4,-2,3};
	int n=sizeof(a)/sizeof(a[0]);
	
	//build the tree array
	int *tree=new int[4*n+1];
	
	int index=1;
	int s=0;
	int e=n-1;  
	 
	buildTree(tree,a,index,s,e);
	
	//updateNode(tree,1,s,e,2,8);
	rangeUpdate(tree,1,s,e,1,2,4);
	
	int no_of_q;
	cin>>no_of_q;
	while(no_of_q--){
		int qs,qe;
		cin>>qs>>qe;
		cout<<"Min Value between "<<qs<<" and "<<qe<<" :";
		cout<<query(tree,index,s,e,qs,qe);	
	}
	
	
		
	return 0;
}

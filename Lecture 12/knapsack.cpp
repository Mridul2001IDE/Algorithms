#include<bits/stdc++.h>
using namespace std;

//recursive approach
//N - no of items, W- weight of bag
int knapsack(int wts[],int prices[],int N,int W){
	
	if(N==0||W==0){
		return 0;
	}
	
	//otherwise
	int i=N-1;
	int inc=0,exc=0;
	
	// current item ko lelo
	if(wts[i]<=W){
		inc=prices[i]+knapsack(wts,prices,N-1,W-wts[i]);
	}
	
	//current item chhod do
	exc=knapsack(wts,prices,N-1,W);
	
	return max(inc,exc);
	
}

//using DP


int main(){
	
	int wts[]={2,1,3,2};
	int prices[]={1,3,5,2};
	cout<<knapsack(wts,prices,4,6);
	return 0;
}

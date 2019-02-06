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
int dpKnapsack(int wts[],int prices[],int N,int W){
	
	int dp[100][100]={0};
	
	for(int n=1;n<=N;n++){
		
		for(int w=1;w<=W;w++){
			
			//current item
			int i=n-1;
			int inc=0,exc=0;
			
			if(wts[i]<=w){
				inc=prices[i]+dp[n-1][w-wts[i]];
			}
			exc=dp[n-1][w];
			dp[n][w]=max(inc,exc);
		}
	}
	return dp[N][W];
}

//if the thief can pick the same item more the one time
int knapsack_repeat(int wts[],int prices[],int N,int W){
	
	if(N==0||W==0){
		return 0;
	}
	
	//otherwise
	int i=N-1;
	int inc=0,exc=0;
	
	// current item ko lelo
	if(wts[i]<=W){
		inc=prices[i]+knapsack_repeat(wts,prices,N,W-wts[i]);
	}
	
	//current item chhod do
	exc=knapsack_repeat(wts,prices,N-1,W);
	
	return max(inc,exc);
	
}

int main(){
	
	int wts[]={2,1,3,2};
	int prices[]={1,3,5,2};
	cout<<knapsack(wts,prices,4,6)<<" "<<dpKnapsack(wts,prices,4,6)<<" "<<knapsack_repeat(wts,prices,4,6);
	return 0;
}

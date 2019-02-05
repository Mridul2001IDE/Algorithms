#include<bits/stdc++.h>
using namespace std;

//using recursion
int waysToOne(int n){
	
	if(n==1){
		return 0;
	}
	
	int op1,op2,op3;
	op1=op2=op3=INT_MAX;
	
	//divisible by 2
	if(n&1==0){
		op2=waysToOne(n/2);
	}
	
	//divisible by 3
	if(n%3==0){
		op3=waysToOne(n/3);
	}
	
	op1=waysToOne(n-1);
	
	return min(op1,min(op2,op3))+1;
}

//using dp
void waysToOneDP(int n){
	
	int *dp=new int[n]{0};
	//dp[0]=0
	//dp[1]=0
	
	for(int i=2;i<=n;i++){
		dp[i]=INT_MAX;
		
		if(i%2==0){
			dp[i]=min(dp[i],dp[i/2]+1);
		}
		
		if(i%3==0){
			dp[i]=min(dp[i],dp[i/3]+1);	
		}
		
		dp[i]=min(dp[i],dp[i-1]+1);
	}
	
	cout<<dp[n];
	
}

int main(){
	int n;
	cin>>n;
	cout<<waysToOne(n)<<"\n";
	waysToOneDP(n);
	return 0;
}

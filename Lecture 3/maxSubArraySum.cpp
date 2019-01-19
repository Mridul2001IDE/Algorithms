#include<bits/stdc++.h>
using namespace std;

//kadane's algo
int maxSubArraySum(int *a,int n){
	
	int currentSum=0,maxSum=0;
	
	for(int i=0;i<n;i++){
		
		currentSum+=a[i];
		if(currentSum<0){
			currentSum=0;
		}
		if(currentSum>maxSum){
			maxSum=currentSum;
		}
		
	}
	
	return maxSum;
	
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	cout<<maxSubArraySum(a,n);
	
	return 0;
}

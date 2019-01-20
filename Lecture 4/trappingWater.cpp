#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int a[]={0,1,0,2,1,0,1,3,2,1,2,1};
	int n=sizeof(a)/sizeof(int);
	
	//computing left se max building height array
	
	int left_max=a[0];
	int right_max=a[n-1];
	int left[n];
	int right[n];
	
	for(int i=0;i<n;i++){
		if(a[i]>left_max){
			left_max=a[i];
			left[i]=a[i];
		}else left[i]=left_max;
	}
	
	//computing right se max building height array
	
	for(int i=n-1;i>=0;i--){
		if(a[i]>right_max){
			right_max=a[i];
			right[i]=a[i];
		}else right[i]=right_max;
	}
	
	//calculating the total water trapped
	int ans=0;
	
	for(int i=0;i<n;i++){
		ans=ans+min(right[i],left[i])-a[i];
	}
	
	cout<<ans;
	
	return 0;
}

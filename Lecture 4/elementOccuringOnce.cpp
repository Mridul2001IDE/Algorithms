//every element occuring twice except one
#include<bits/stdc++.h>
using namespace std;

int main(){
	int a[]={3,5,7,2,5,7,3};
	int n=sizeof(a)/sizeof(int);
	int ans=0;
	
	for(int i=0;i<n;i++)
	ans=ans^a[i];
	
	cout<<ans;
		
	return 0;
}

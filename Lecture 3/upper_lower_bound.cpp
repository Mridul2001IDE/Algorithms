//upper and lower bound of a sorted array
#include<bits/stdc++.h>
using namespace std;

int upperBound(int *a,int n,int key){
	
	int s=0;
	int e=n-1;
	int ans=-1;
	
	while(s<=e){
		int mid=(s+e)/2;
		
		if(a[mid]==key){
			ans=mid;
			s=mid+1;
		}else if(a[mid]>key){
			e=mid-1;
		}else {
			s=mid+1;
		}
	}
	
	return ans;
	
}


int lowerBound(int *a,int n,int key){
	
	int s=0;
	int e=n-1;
	int ans=-1;
	
	while(s<=e){
		int mid=(s+e)/2;
		
		if(a[mid]==key){
			ans=mid;
			e=mid-1;
		}else if(a[mid]>key){
			e=mid-1;
		}else {
			s=mid+1;
		}
	}
	
	return ans;
	
}

int main(){
	int a[]={1,2,2,2,4,7,8};
	int n=sizeof(a)/sizeof(int);
	int key=2;
	cout<<lowerBound(a,n,key)<<" "<<upperBound(a,n,key);
	
	return 0;
}

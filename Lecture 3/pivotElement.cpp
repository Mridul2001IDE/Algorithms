//pivot element in a sorted and rotated array
#include<bits/stdc++.h>
using namespace std;

int findPivot(int *a,int n){
	int s=0,e=n-1;
	while(s<=e){
		
		int mid=(s+e)/2;
		if(a[mid]>a[mid+1]){
			return mid;
		}else if(a[mid]<a[mid-1]){
			return mid-1;
		}else if(a[s]<=a[mid]){
			s=mid+1;
		}else e=mid-1;
		
	}
	return -1;
}

int main(){
	
	int a[]={5,6,7,1,2,3,4};
	int n=sizeof(a)/sizeof(int);
	cout<<findPivot(a,n);	
	
	return 0;
}

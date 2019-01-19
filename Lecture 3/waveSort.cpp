#include<bits/stdc++.h>
using namespace std;

void waveSort(int *a,int n){
	
	// Traverse all even elements 
    for (int i = 0; i < n; i+=2) 
    { 
        // If current even element is smaller than previous 
        if (i>0 && a[i-1] > a[i] ) 
            swap(a[i],a[i-1]); 
  
        // If current even element is smaller than next 
        if (i<n-1 && a[i] < a[i+1] ) 
            swap(a[i], a[i + 1]); 
    } 
	
}

int main(){
	int a[]={1,4,2,6,8,9};
	int n=sizeof(a)/sizeof(int);
	waveSort(a,n);
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	
	return 0;
}

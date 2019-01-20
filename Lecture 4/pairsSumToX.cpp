#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int a[]={-3,-2,1,3,5,6,7,8,10,12};
	int n=sizeof(a)/sizeof(int);
	int x=7;
	
	int *i=a;
	int *j=&a[n-1];
	
	while((*i)<(*j)){
		int sum=(*i) + (*j);
		if(sum==x) {
			
			cout<<*i<<" "<<*j<<"\n";
			i++;
			j--;
		
		}
		else if(sum>x) j--;
		else i++;
	}
	
	return 0;
}

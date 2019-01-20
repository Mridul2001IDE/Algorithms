//count no of set bits in a no. in O(no. of set bits)
#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	cin>>n;
	int count=0;
	while(n>0){
		count++;
		n=n&(n-1);
	}
	cout<<count;
	return 0;
}

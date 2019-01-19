//square root of a no. using binary  serach
#include<bits/stdc++.h>
using namespace std;

float squareRoot(int n,int p){
	
	float ans;
	//binary search for finding integer part
	int s=0,e=n;
	while(s<=e){
		
		int mid=(s+e)/2;
		if(mid*mid==n){
			return mid;
		}else if(mid*mid>n){
			e=mid-1;
		}else {
			s=mid+1;
			ans=mid;
		}
	}
	// floating part
	float inc=0.1;
	for(int place=1;place<=p;place++){
		while(ans*ans<=n){
			ans+=inc;
		}
		
		ans=ans-inc;
		inc=inc/10;
		
	}
	
	return ans;
	
}

int main(){
	int n,p;
	cin>>n>>p;
	cout<<squareRoot(n,p); 
	return 0;
} 

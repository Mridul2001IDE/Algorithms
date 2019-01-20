//every element occuring twice except two element
#include<bits/stdc++.h>
using namespace std;

void findNumbers(int a[],int n){
	
	int x=0;
	for(int i=0;i<n;i++){
		x=x^a[i];
	}
	
	int ans=x;
	
	//x is not zero so atleast one set bit is present
	int pos=0;
	//calculating the pos of set bit
	while(x>0){
		//checking the last bit
		if(x&1){
			break;
		}
		pos++;
		x=x>>1;
	}
	
	//Mask
	//creating a no from pos and & it with nos return 1 only if they have 1 at pos
	int mask=1<<pos;
	int no1=0;
	for(int i=0;i<n;i++){
		if(mask&a[i]) {
			no1=no1^a[i];
		}
	}
	
	cout<<no1<<" ";
	int no2=ans^no1;
	cout<<no2;
	
}

int main(){
	int a[]={6,1,3,5,1,3,7,6};
	int n=sizeof(a)/sizeof(int);
	
	findNumbers(a,n);
	
	return 0;
}

//check if 2 strings are permutations of one another
#include<bits/stdc++.h>
using namespace std;

string isPermutation(char *s1,char *s2){
	int n=strlen(s1);
	int arr[256]={0};
	for(int i=0;i<n;i++){
		
		arr[int(s1[i])]+=1;
		arr[int(s2[i])]-=1;
		
	}
	
	for(int i=0;i<256;i++){
		if(arr[i]==0) continue;
		else return "No";
	}
	
	return "Yes";
	
}

int main(){
	
	char s1[100],s2[100];
	cin>>s1>>s2;
	
	cout<<isPermutation(s1,s2);
	
	return 0;
}

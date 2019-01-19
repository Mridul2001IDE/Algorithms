// read n strings from user and print largest string 
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	cin.ignore();
	char s[100];
	char str[100];
	int len=0;
	int largestLen=0;
	for(int i=0;i<n;i++){
		cin.getline(s,100);
		len=strlen(s);
		if(len>largestLen){
			largestLen=len;
			strcpy(str,s);
		}		
	}
	
	cout<<str;
	
	return 0;
}

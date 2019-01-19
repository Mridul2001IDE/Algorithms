#include<bits/stdc++.h>
using namespace std;

void phoneKeyPad(string *m,char *input,char *output,int i=0,int j=0){
	
	//base case
	if(input[i]=='\0'){
		output[j]='\0';
		cout<<output<<"\n";
	}
	
	if(input[i]=='1'||input[i]=='0'){
		return phoneKeyPad(m,input,output,i+1,j);
	}
	
	//current digit
	int digit=input[i]-'0';
	for(int k=0;k<m[digit].size();k++){
		output[j]=m[digit][k];
		phoneKeyPad(m,input,output,i+1,j+1);
	}
	
	
}

int main(){
	string s[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	
	char input[10];
	cin>>input;

	char output[10];

	phoneKeyPad(s,input,output);

	return 0;
}

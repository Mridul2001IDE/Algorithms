//mapping ques 1-A,2-B ... 26-Z 
// given n print all combination of possible strings

#include<bits/stdc++.h>
using namespace std;

void func(char *input,char *output,int i=0,int j=0){
	//base case
	if(input[i]=='\0')
	{
		output[j]='\0';
		cout<<output<<"\n";
		return;
	}
	
	//recursive case
	//take 1 char at a time
	//converting to corr character
	int digit=input[i]-'0';
	char ch=64+digit;
	
	output[j]=ch;
	func(input,output,i+1,j+1);
	
	//taking 2 char at a time
	//then only we can take 2 char
	if(input[i+1]!='\0'){
		
		int secondDigit=input[i+1]-'0';
		int no=10*digit+secondDigit;
		if(no<=26){
			ch=64+no;
			output[j]=ch;
			func(input,output,i+2,j+1);
		}
			
	}
		
	
}

int main(){
	char input[]="1234";
	char output[100];
	
	func(input,output);
	
	return 0;
}

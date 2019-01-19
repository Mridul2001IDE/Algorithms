//iteratively finding all subsequences of string
#include<bits/stdc++.h>
using namespace std;

//given 'abc' and no as 5 it returns 'a'
void mask(char input[],int n){
	int i=0;
	//each time right shift the no to get last bit and & it with 1 to see it is 0 or 1
	for(;n>0;n>>=1){
		if(n&1){
			cout<<input[i];
		}
		i++;
	}cout<<"\n";
}

int main(){
	char input[10];
	cin>>input;
	int n=strlen(input);
	//run the for loop 2^n - 1 times
	for(int i=0;i<(1<<n);i++){
		mask(input,i);
	}
	return 0;
}


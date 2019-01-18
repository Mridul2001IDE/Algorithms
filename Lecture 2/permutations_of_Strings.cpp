#include<bits/stdc++.h>
using namespace std;
set<string> ss;
void printPermutation(char *input,int i=0){
	
	//base case
	if(input[i]=='\0'){
		string s(input);
		ss.insert(s);
		return;
	}
	
	//rec case
	for(int j=i;input[j]!='\0';j++){
		swap(input[i],input[j]);
		printPermutation(input,i+1);
		//backtracking - to restore the original array
		swap(input[i],input[j]);
	}
	
	
}

int main(){
	
	char input[10]="aabc";
	
	printPermutation(input);

	for(auto it=ss.begin();it!=ss.end();it++){
		cout<<*it<<" ";
	}

	return 0;
}

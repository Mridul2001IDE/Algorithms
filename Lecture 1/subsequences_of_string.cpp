#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

void subsequences(char input[],char output[],vector<string> &vs,int i=0,int j=0){
	//base case
	if(input[i]=='\0'){
		output[j]='\0';
		string s(output);
		vs.push_back(s);
		return;
	}
	
	//reccursive call
	//include ith char
	output[j]=input[i];
	subsequences(input,output,vs,i+1,j+1);
	
	//exclude ith char
	subsequences(input,output,vs,i+1,j);
}

int main(){
	
	char input[]="abc";
	char output[10];
	vector<string> vs;
	subsequences(input,output,vs);
	sort(vs.begin(),vs.end());
	for(int i=0;i<vs.size();i++){
		cout<<vs[i]<<" ";
	}
	return 0;
}

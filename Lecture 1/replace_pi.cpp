#include<iostream>
using namespace std;

void replacePi(char *input,int i){
	
	//base case
	if(input[i]=='\0'||input[i+1]=='\0'){
		return ;
	}
	
	//rec step
	if(input[i]=='p'&&input[i+1]=='i'){
		int j=i+2;
		while(input[j]!='\0'){
			j++;
		}	
		while(j>=i+2){
		input[j+2]=input[j];
		j--;
		}
		input[i]='3';
		input[i+1]='.';
		input[i+2]='1';
		input[i+3]='4';
		replacePi(input,i+4);
	}
	
	else {
		replacePi(input,i+1);
	}
	
}

int main(){
	
	char input[100]="xpiypizph";
	cout<<input<<endl;
	replacePi(input,0);
	cout<<input;
	return 0;
}

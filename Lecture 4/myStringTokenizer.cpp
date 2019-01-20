#include<bits/stdc++.h>
using namespace std;

char* mystrtok(char *str,char delim){
	
	static char* input=NULL;
	
	if(str!=NULL){
		input=str;
	}
	
	if(input==NULL){
		return NULL;
	}
	
	char* output=new char[strlen(input)+1];
	
	int i=0;
	
	for(i=0;input[i]!='\0';i++){
		if(input[i]!=delim){
			output[i]=input[i];
		}else{
			output[i]='\0';
			input=input+i+1;
			return output;
		}
	}
	
	//handling for the last word
	output[i]=NULL;
	input=NULL;
	return output;
	
}

int main(){
	
	char input[]="hey it is me";
	
	char* token=mystrtok(input,' ');
	while(token!=NULL){
		
		cout<<token<<"\n";
		token=mystrtok(NULL,' ');
		
	}
	
	return 0;
}

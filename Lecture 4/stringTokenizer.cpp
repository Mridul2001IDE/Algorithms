#include<bits/stdc++.h>
using namespace std;
int main(){
	
	char input[]="hey it is me";
	
	char*token=strtok(input," ");
	while(token!=NULL){
		
		cout<<token<<"\n";
		token=strtok(NULL," ");
		
	}
	
	return 0;
}

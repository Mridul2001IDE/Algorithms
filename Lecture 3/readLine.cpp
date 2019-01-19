// building own readline func
#include<bits/stdc++.h>
using namespace std;

void readline(char *s,int n,char delim){
	int i=0;
	char ch=cin.get();
	while(ch!=delim){
		
		s[i]=ch;
		i++;
		if(i==n-1){
			break;
		}
		ch=cin.get();
	}
	s[i]='\0';
	
}

int main(){
	char s[10];
	readline(s,10,'$');
	cout<<s;
	return 0;
}

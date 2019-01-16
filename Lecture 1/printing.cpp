//print nos from 1 to n

#include<iostream>
using namespace std;

void print_dec(int n){
	if(n==0) return;
	cout<<n;
	print_dec(n-1);
}

void print_inc(int n){
	if(n>1) print_inc(n-1);
	cout<<n;
}

int main(){
	print_dec(5);
	cout<<"\n";
	print_inc(5);
	return 0;
}

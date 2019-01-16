//power function

#include<iostream>
#include<math.h>
using namespace std;

int power(int a,int b){
	if(b==0) return 1;
	int smallpower=power(a,b/2);
	if(b&1) return a*smallpower*smallpower;
	else return smallpower*smallpower;

}

int main(){
	int a,b;
	cin>>a>>b;
	cout<<power(a,b);
	return 0;
}

//tower of hanoi
#include<iostream>
using namespace std;

void toh(int n,char source,char helper,char dest){
	
	//base case
	if(n==0) return;
	
	//rec call
	toh(n-1,source,dest,helper);
	
	cout<<"move "<<n<<" from "<<source<<" to "<<dest<<"\n";
	
	toh(n-1,helper,source,dest);
	
}

int steps(int n){
	if(n==0) return 0;
	return 2*steps(n-1)+1;
}

int main(){
	
	int n;
	cin>>n;
	toh(n,'A','B','C');
	cout<<"No of steps "<<steps(n);
	return 0;
}

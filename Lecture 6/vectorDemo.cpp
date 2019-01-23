#include<bits/stdc++.h>
//#include "vectorImplementation.h"
#include "genericTypeVector.h"

using namespace std;

int main(){
	
	//generic Vector
	Vector<char> v;
	
	for(int i=65;i<80;i++){
		v.push_back(i);
	}	
	
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	
	return 0;
}

//rotating the matrix by 90 degree clockwise
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n][n];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];		
		}
	}
	
	//transposing the matrix
	
	for (int i = 0; i < n; i++) 
        for (int j = i+1; j < n; j++) 
			swap(a[i][j],a[j][i]);


	//mirror image of the matrix


	
	//printing
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}cout<<"\n";
	}
				
	return 0;
}

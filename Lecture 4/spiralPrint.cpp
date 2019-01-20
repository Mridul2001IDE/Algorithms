//rotating the matrix by 90 degree clockwise
#include<bits/stdc++.h>
using namespace std;

void spiralPrint(int a[][10],int m,int n){
	
	int startRow=0,endRow=m-1;
	int startCol=0,endCol=n-1;
	
	while(startRow<=endRow && startCol<=endCol){
		
		//Print the start row
		
		for(int i=startCol;i<=endCol;i++){
			cout<<a[startRow][i]<<" ";
		}
		startRow++;
		
		//Print the end col
		
		for(int i=startRow;i<=endRow;i++){
			cout<<a[i][endCol]<<" ";
		}
		endCol--;
		
		//to remove duplicate - if condition
		//Print the end row
		if(endRow>startRow){
		
		for(int i=endCol;i>=startCol;i--){
			cout<<a[endRow][i]<<" ";
		}
		endRow--;
		}
	
		//to remove duplicate - if condition
		//Print the start col
		if(startCol<endCol){
			
		for(int i=endRow;i>=startRow;i--){
			cout<<a[i][startCol]<<" ";
		}
		startCol++;
		}
	}
	
}

int main(){
	int n,m;
	int a[10][10];
	cin>>m>>n;
	
	int value=1;
	
	//making a dummy array
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j]=value++;
			cout<<a[i][j]<<" ";		
		}cout<<"\n";
	}
	
	cout<<"\n";
	
	spiralPrint(a,m,n);
	
		
	return 0;
}

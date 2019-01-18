#include<bits/stdc++.h>
using namespace std;

//helper fuction
bool canPlace(int mat[9][9],int i,int j,int no,int n)
{
	//row
	for(int x=0;x<n;x++){
		if(mat[i][x]==no) return false;
	}
	
	//col
	for(int x=0;x<n;x++){
		if(mat[x][j]==no) return false;
	}
	
	//subgrid
	int rn=sqrt(n);
	//starting point of subgrid
	int sx=(i/rn)*rn;
	int sy=(j/rn)*rn;
	
	for(int x=sx;x<sx+rn;x++){
		for(int y=sy;y<sy+rn;y++){
			if(mat[x][y]==no){
				return false;
			}
		}
	}
	
	return true;
}
bool solveSoduko(int mat[9][9],int i,int j,int n){
	
	//base case
	if(i==n){
		// print soduko
		for(int a=0;a<n;a++){
			for(int b=0;b<n;b++){
				cout<<mat[a][b]<<" ";
			}cout<<"\n";
		}
		
		return true;
	}
	
	if(j==n){
		return solveSoduko(mat,i+1,0,n);
	}
	
	//skip the input filled cell
	if(mat[i][j]!=0){
		return solveSoduko(mat,i,j+1,n);
	}
	
	//non filled cell
	for(int no=1;no<=n;no++){
		if(canPlace(mat,i,j,no,n)){
			mat[i][j]=no;
			bool solveHuiKya=solveSoduko(mat,i,j+1,n);
			if(solveHuiKya==true){
				return true;
			}
			mat[i][j]=0;
		}
	}
	
	return false;
	
}

int main(){
	int mat[9][9]={
		{5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9}
	};
	int n=9;
	solveSoduko(mat,0,0,n);
	return 0;
}

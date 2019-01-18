#include<bits/stdc++.h>
using namespace std;

bool ratInMaze(char maze[][10],int sol[][10],int i,int j,int m,int n){
	//base case
	if(i==m&&j==n){
		sol[i][j]=1;
		//print sol
		
		for(int a=0;a<=m;a++){
			for(int b=0;b<=n;b++){
				cout<<sol[a][b]<<" ";
			}cout<<"\n";
		}
		
		return true;
	}
	
	//rec case
	//assume path goes through current cell
	sol[i][j]=1;
	//going right
	if(j+1<=n&&maze[i][j+1]!='x'){
		bool rastaMila=ratInMaze(maze,sol,i,j+1,m,n);
		
		if(rastaMila==true){
			return true;
		}
	}
	//going down
	if(i+1<=m&&maze[i+1][j]!='x'){
		bool rastaMila=ratInMaze(maze,sol,i+1,j,m,n);
		
		if(rastaMila==true){
			return true;
		}
	}
	
	//path not found through that cell therefore assumption wrong
	//backtracking
	sol[i][j]=0;
	return false;
	
}


int main(){
	
	char maze[10][10]={
	"0000xx",
	"00xx0x",
	"x000x0",
	"00x000"
	};	
	
	int sol[10][10]={0};
	//dest cell
	int m=3,n=5;
	ratInMaze(maze,sol,0,0,m,n);
	return 0;
}

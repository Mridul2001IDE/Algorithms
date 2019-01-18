#include<iostream>
using namespace std;

//checks if the queen can be placed at ith and jth pos
bool canPlace(int board[][100],int i,int j,int n){
	//check for column
	for(int row=0;row<i;row++){
		if(board[row][j]==1) return false;
	}
	
	//check for left diagnol
	int x=i,y=j;
	while(x>=0&&y>=0){
		if(board[x][y]==1) return false;
		x--;
		y--;
	}
	
	//check for right dignol
	x=i;
	y=j;
	while(x>=0&&y<n){
		if(board[x][y]==1) return false;
		x--;
		y++;
	}
	
	return true;
	
}

//i is for the row, not given j since the algo will decide where to place the queen
bool solveNQueen(int board[][100],int n,int i=0){
	
	//base case
	if(i==n){
		//print the board
		for(int a=0;a<n;a++){
			for(int b=0;b<n;b++){
				cout<<board[a][b]<<" ";
			}cout<<"\n";
		}
		
		return true;
	}
	
	//try to place the queen at each pos in current row
	for(int j=0;j<n;j++){
		if(canPlace(board,i,j,n)){
			
			board[i][j]=1;
			
			bool queenRakhPayeKya=solveNQueen(board,n,i+1);
			
			if(queenRakhPayeKya==true){
				return true;
			}
			
			//backtracking
			board[i][j]=0;
			
		}

	}
	
	return false;
	
}

int main(){
	int board[100][100]={0};
	
	int n;
	cin>>n;
	
	solveNQueen(board,n);
	
	return 0;
}

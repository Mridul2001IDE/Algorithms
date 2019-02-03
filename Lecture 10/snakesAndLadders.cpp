// snakes and ladders
#include<bits/stdc++.h>
# define hashmap unordered_map<T,vector<T>> 
using namespace std;

template<typename T>
class Graph{
	
	//no of nodes - vertices
	int V;
	hashmap l;
	
	public:
		Graph(int v=0){
			V=v;
		}
		
		void addEdge(T u,T v,bool bidir=true){
			l[u].push_back(v);
			if(bidir){
			l[v].push_back(u);
			}
			V=l.size();
		}
		
		//bfs
		void bfs(T src,T dest){
			unordered_map<T,bool> visited;
			
			//calculating min distances from the src
			unordered_map<T,int> distance;
			
			//shortest path between 2 cities
			unordered_map<T,T> parent;
			
			for(auto it=l.begin();it!=l.end();it++){
				distance[it->first]=INT_MAX;
			}
			
			queue<T> q;
			q.push(src);
			visited[src]=true;
			distance[src]=0;
			parent[src]=src;
			
			while(!q.empty()){
				T f=q.front();
//				cout<<f<<" ";
				q.pop();
				
				for(int i=0;i<l[f].size();i++){
					if(!visited[l[f][i]]){
						q.push(l[f][i]);
						visited[l[f][i]]=true;
						distance[l[f][i]]=distance[f]+1;
						parent[l[f][i]]=f;
					}
				}
				
			}
			
			//path from src to dest
			T temp;
			temp=dest;
			while(temp!=src){
				cout<<temp<<"<--";
				temp=parent[temp];
			}cout<<src;
		}
	
		void printAdjList(){
			
			for(auto i=l.begin();i!=l.end();i++){
				T current=i->first;
				cout<<current<<"->";
				
				for(int j=0;j<l[current].size();j++){
					cout<<l[current][j]<<" ";
				}
				cout<<"\n";
			}
			
		}	
};

int main(){
	
	Graph<int> g;
	
	//board
	int board[50]={0};
	// negative no for a snake which gives negative jump and positive no for a ladder
	board[2]=13;
	board[5]=2;
	board[9]=18;
	board[18]=11;
	board[17]=-13;
	board[20]=-14;
	board[24]=-8;
	board[25]=10;
	board[32]=-2;
	board[34]=-22;

	//adding all edges - 6*6 board
	for(int u=0;u<36;u++){
		for(int dice=1;dice<=6;dice++){
			int v=u+dice+board[u+dice];
			if(v<=36){
				g.addEdge(u,v,false);
			}
		}
	}
	
	g.bfs(0,36);
	
	return 0;
}


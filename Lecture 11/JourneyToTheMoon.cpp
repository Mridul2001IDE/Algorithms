//journey to the moon question
#include<bits/stdc++.h>
#include<list>

using namespace std;

class Graph{
	
	//no of nodes - vertices
	int V;
	list<int> *l;
	
	public:
		Graph(int v){
			V=v;
			l=new list<int>[V];
		}
		
		void addEdge(int u,int v,bool bidir=true){
			l[u].push_back(v);
			if(bidir){
			l[v].push_back(u);
			}
		}
		
		//dfs helper func
		void dfsHelper(int i,bool visited[],int &cp_size){
			visited[i]=true;
			cp_size++;
			for(auto it=l[i].begin();it!=l[i].end();it++){
				if(!visited[*it]){
					dfsHelper(*it,visited,cp_size);
				}
			}
		}
		
		//dfs
		int dfsMoon(){
			bool* visited=new bool[V];
			for(int i=0;i<V;i++){
				visited[i]=false;
			}
			
			int total_ways=(V)*(V-1)/2;
			
			for(int i=0;i<V;i++){
				if(!visited[i]){
					//component size
					int cp_size=0;
					dfsHelper(i,visited,cp_size);
					total_ways-=(cp_size*(cp_size-1)/2);
				}
			}
			return total_ways;
		}
	
};

int main(){
	
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(2,3);
	g.addEdge(0,4);

	cout<<g.dfsMoon();
	
	return 0;
}


// depth first search
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
		
		//dfs helper func
		void dfsHelper(T src,unordered_map<T,bool> &visited){
			visited[src]=true;
			cout<<src<<" ";
			for(auto it=l[src].begin();it!=l[src].end();it++){
				if(!visited[*it]){
					dfsHelper(*it,visited);
				}	
			}
			
			
		}
		
		//dfs
		void dfs(){
			unordered_map<T,bool> visited;
			
			for(auto it=l.begin();it!=l.end();it++){
				if(!visited[it->first]){
					dfsHelper(it->first,visited);
				}
				cout<<endl;
			}

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
	
	Graph<string> g;
	g.addEdge("Delhi","Agra");
	g.addEdge("Delhi","jaipur");
	g.addEdge("jaipur","bhopal");
	g.addEdge("Agra","jaipur");
	g.addEdge("Mumbai","bhopal");
	g.addEdge("andaman","nicobar");
	g.dfs();
	
	return 0;
}


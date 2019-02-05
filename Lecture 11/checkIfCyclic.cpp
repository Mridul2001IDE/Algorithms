// detect cycle in graph
#include<bits/stdc++.h>
#include<list>

using namespace std;

class Graph{
	
	//no of nodes - vertices
	int V;
	list<pair<int,int>> *l;
	
	public:
		Graph(int v){
			V=v;
			l=new list<pair<int,int>>[V];
		}
		
		void addEdge(int u,int v,int wt,bool bidir=true){
			l[u].push_back(make_pair(v,wt));
			if(bidir){
			l[v].push_back(make_pair(u,wt));
			}
		}
	
		
		int find(int i,int* parent){
			if(parent[i]==i){
				return i;
			}
			return find(parent[i],parent);
		}
	
		void union_(int x,int y,int* parent){
			
			int xParent=find(x,parent);
			int yParent=find(y,parent);
			parent[yParent]=xParent;
						
		}
	
		//detect cycle in graph
		bool isCyclic(){
			
			int *parent=new int[V];
			//pehle apna parent khud hai
			for(int i=0;i<V;i++){
				parent[i]=i;
			}
			
			//cyclic ka logic - iterate over the edges
			for(int i=0;i<V;i++){
				for(auto j=l[i].begin();j!=l[i].end();j++){
					//edge x or y ke beech mei hai
					int x=i;
					int y=j->first;
					int xParent=find(x,parent);
					int yParent=find(y,parent);
					
					if(xParent==yParent){
						return true;
					}
					union_(x,y,parent);
				}
			}
			return false;
		}
		
};

int main(){
	
	Graph g(6);
	g.addEdge(0,2,1,false);
	g.addEdge(0,3,1,false);
	g.addEdge(1,2,1,false);
	g.addEdge(2,3,1,false);
	g.addEdge(3,4,1,false);
	g.addEdge(3,5,1,false);
	g.addEdge(2,5,1,false);
	g.addEdge(4,5,1,false);
	
	if(g.isCyclic()){
		cout<<"Cyclic hai";
	}else cout<<"Ni hai";
	
	return 0;
}


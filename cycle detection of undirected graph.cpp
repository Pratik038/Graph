#include<iostream>
#include<list>
using namespace std;
class Graph{
	int V;
	list<int> *l;
 public:
 	Graph(int V){
 		this->V=V;
 		l=new list<int>[V];
	 }
	 
	void add(int u,int v){
		l[u].push_back(v);
		l[v].push_back(u);
	}
	bool cyclic_helper(int node,bool *visited,int parent){
		visited[node]=true;
		for(auto nbr:l[node]){
			if(!visited[nbr]){
				bool cycle_mila=cyclic_helper(nbr,visited,node);
				if(cycle_mila)
					return true;
			}
			else if(nbr!=parent)
				return true;
		}
		return false;
	}
	bool contains_cycle(){
		bool *visited=new bool[V];
		for(int i=0;i<V;i++)
			visited[i]=false;
		return cyclic_helper(0,visited,-1);
	}
};

int main(){
	
	Graph g(4);
	g.add(0,1);
	g.add(1,2);
	g.add(2,3);
	if(g.contains_cycle())
		cout<<"Graph has cycle";
	else
		cout<<"Graph has no cycle";
	return 0;
}

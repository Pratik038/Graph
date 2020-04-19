#include<iostream>
#include<map>
#include<list>
using namespace std;
template <typename T>
class Graph{
	map<T,list<T>> l;
 public:
 	Graph(){
	 }
	 void add(T u,T v,bool bidir=true){
	 	l[u].push_back(v);
	 	if(bidir)
	 		l[v].push_back(u);
	 }
	 void dfs_helper(T src,map<T,bool> &visited){
	 	
	 	cout<<src<<" ";
	 	visited[src]=true;
	 	for(T nbr:l[src]){
	 		if(!visited[nbr])
	 			dfs_helper(nbr,visited);
		 }
	 }
	 void dfs(T src){
	 	
	 	map<T,bool> visited;
	 	for(auto p: l){
	 		T node=p.first;
	 		visited[node]=false;
		 }
		 dfs_helper(src,visited);
	 }
};
int main(){
	Graph <int>g;
	g.add(0,1);
	g.add(1,2);
	g.add(2,4);
	g.dfs(0);
	return 0;
}

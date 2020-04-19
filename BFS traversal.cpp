#include<iostream>
#include<map>
#include<list>
#include<queue>
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
	 void bfs(T src){
	 	map<T,bool> visited;
	 	queue<T> q;
	 	
	 	q.push(src);
	 	visited[src]=true;
	 	
	 	while(!q.empty()){
	 		T node=q.front();
	 		q.pop();
	 		cout<<node<<" ";
	 		for(auto i : l[node]){
	 			if(!visited[i]){
	 				q.push(i);
	 				visited[i]=true;
				 }
			 }
		 }
	 }
};
int main(){
	Graph <int>g;
	g.add(0,1);
	g.add(1,2);
	g.add(2,4);
	g.bfs(0);
	return 0;
}

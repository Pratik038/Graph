#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph{
	int V;
	list<int> *adjList;
 public:
 	Graph(int v){
 		V=v;
 		adjList = new list<int>[V]; 
	 }
	 void addEdge(int u,int v,bool bidir=true){
	 	adjList[u].push_back(v);
	 	if(bidir)
	 		adjList[v].push_back(u);
	 }
	 void print(){
	 	for(int i=0;i<V;i++){
	 		cout<<i<<"->";
	 		for(int node:adjList[i])
	 			cout<<node<<",";
	 		cout<<endl;
		 }
	 }
	 
	 void BFS(int src,int dest){
	 	queue<int> q;
	 	bool *visited=new bool[V+1]{0};
	 	int *dist=new int[V+1]{0};
	 	int *parent=new int[V+1];
	 	for(int i=0;i<V;i++) parent[i]=-1;
	 	
	 	q.push(src);
	 	visited[src]=true;
	 	
	 	while(!q.empty()){
	 		int node=q.front();
	 		cout<<node<<" ";
	 		q.pop();
	 		for(int neighbour:adjList[node]){
	 			if(!visited[neighbour]){
	 				q.push(neighbour);
	 				visited[neighbour]=true;
	 				dist[neighbour]=dist[node]+1;
	 				parent[neighbour]=node;
				 }
			 }
		 }
		 cout<<endl;
		 cout<<"Shortest path is :"<<dist[dest]<<endl;
		 cout<<"Shortest path is :";
		 int temp=dest;
		 while(temp!=-1){
		 	cout<<temp<<"<--";
		 	temp=parent[temp];
		 }
	 }
};

int main(){
	Graph g(8);
	g.addEdge(0,1);
	g.addEdge(1,7);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(2,4);
	g.addEdge(7,4);
	g.addEdge(6,4);
	g.addEdge(4,5);
	g.print();
	g.BFS(0,4);
	return 0;
}

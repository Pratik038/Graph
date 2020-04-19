#include<iostream>
#include<map>
#include<list>
#include<cstring>
using namespace std;

template <typename T>
class Graph{
	map<T,list<T>> adjList;
 public:
 	Graph(){
	 }
	 void addEdge(T u,T v,bool bidir=true){
	 	adjList[u].push_back(v);
	 	if(bidir)
	 		adjList[v].push_back(u);
	 }
	 
	 void print(){
	 	for(auto row:adjList){
	 		T key=row.first;
	 		cout<<key<<"->";
	 		for(T element:row.second)
	 			cout<<element<<",";
	 		cout<<endl;
		 }
	 }
};
int main(){
	Graph<string> g;
	g.addEdge("Ghato","Bhopal");
	g.addEdge("Ghato","Ranchi");
	g.addEdge("Bhopal","Goa");
	g.addEdge("Bhopal","Ranchi");
	g.addEdge("Ranchi","Goa");
	g.print();
	return 0;
}

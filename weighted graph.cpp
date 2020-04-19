#include<iostream>
#include<list>
#include<map>
#include<cstring>
using namespace std;

class Graph{
	
	map<string,list<pair<string,int>>> l;
 public:
 	Graph(){
	 }
	 void addEdge(string x,string y,int wt,bool bidir=true){
	 	l[x].push_back(make_pair(y,wt));
	 	if(bidir)
	 		l[y].push_back(make_pair(x,wt));
	 }
	 void print(){
	 	for(auto p:l){
	 		string city=p.first;
	 		cout<<city<<"->";
	 		auto nbrs=p.second;
	 		for(auto nbr:nbrs){
	 			string dest=nbr.first;
	 			int dist=nbr.second;
	 			cout<<dest<<" "<<dist<<",";
			 }
			 cout<<endl;
		 }
	 }
};

int main(){
	Graph g;
	g.addEdge("A","B",20);
	g.addEdge("A","C",10);
	g.addEdge("C","D",30);
	g.print();
	return 0;
}

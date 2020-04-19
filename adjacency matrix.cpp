#include<iostream>
using namespace std;

struct Graph{
	int V;
	int E;
	int **Adj;
};

Graph* adjMatrix(int v,int e){
	Graph *G = new Graph;
	if(!G)
		return NULL;
	G->V=v;
	G->V=e;
	G->Adj= new int*[G->V];
	for(int i=0;i<G->V;i++)
		for(int j=0;j<G->V;j++)
		 	G->Adj[i][j]=0;
	cout<<"Enter the edges in pair:";
	for(int i=0;i<G->E;i++){
		int p,q; cin>>p>>q;
		G->Adj[p][q]=1;
		G->Adj[q][p]=1;
	}
	return G;
}

int main(){
	Graph *G;
	int v,e;
	cout<<"Enter the number of vertices:";
	cin>>v;
	cout<<"Enter the number of edges:";
	cin>>e;
	G=adjMatrix(v,e);
	return 0;
}

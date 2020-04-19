#include<iostream>
using namespace std;

int main(){
	int stages,n;
	cout<<"Enter number of stages:";
	cin>>stages;
	cout<<"Enter number of vertices:";
	cin>>n;
	int cost[n+1],d[n+1],path[stages];
	int c[n+1][n+1];
	for(int i=0;i<n+1;i++) c[0][i]=0;
	cout<<"Enter the edges in adjacency matrix:";
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		 cin>>c[i][j];
	cost[n]=0;
	for(int i=n-1;i>0;i--){
		int min=INT_MIN;
		for(int k=i+1;k<=n;k++){
			
		}
	}
	return 0;
}

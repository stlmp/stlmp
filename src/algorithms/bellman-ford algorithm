#include<bits/stdc++.h>
using namespace std;
struct edge{
	int src;
	int dest;
	int wt;
};
int main()
{
	int a,b;     // a=number of vertices
                 // b= number of edges

	int s,d,w;   // s=source
                 // d=destination
                 // w=weight
    cout<<"enter number of vertices and edges: ";
	cin>>a>>b;
	cout<<endl<<"enter source, destination and weight of each edge"<<endl;
	edge E[b];
	for(int i=0;i<b;i++)
	{
		cin>>s>>d>>w;
		E[i].src=s;
		E[i].dest=d;
		E[i].wt=w;
	}
	//implementation
	int dist[a];
	dist[0]=0;
	for(int i=1;i<a;i++)
	{
	 dist[i]=INT_MAX;
	}
	for(int i=0;i<a-1;i++)
	{
		for(int j=0;j<b;j++)
		{
			int u = E[j].src;
			int v = E[j].dest;
			int w = E[j].wt;
			if(dist[u]!=INT_MAX&&dist[u]+w<dist[v])
			{
				dist[v]=dist[u]+w;
			}
		}
	}
	for(int j=0;j<b;j++)
		{
			int u = E[j].src;
			int v = E[j].dest;
			int w = E[j].wt;
			if(dist[u]!=INT_MAX&&dist[u]+w<dist[v])
			{
				cout<<"negative cycle";
				break;
			}
		}

    cout<<"the shortest distance from source(node 0) to all other vestices is: "<<endl;
	for(int i=0;i<a;i++)
	{
	  cout<<i<<" "<<dist[i];
	  cout<<endl;
	}

	return 0;

}

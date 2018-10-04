#include<iostream>
#include<list>
#include<queue>
#include<map>
#include<stack>
#include<vector>
using namespace std;

stack<int> final;  //to store the final output

class Graph{
 
 int V;
 list<int> *l;

public:
  Graph(int a)
  {
  	V=a;
  	l=new list<int>[a];
    
  }

  void addnode(int u,int v)
  {

  	l[u].push_back(v);
   	
  }

   void DFS_helper(int i,stack<int>&final,vector<int> &visited)
  {	
    if(visited[i]!=1)
    {
      visited[i]=1;
      
      for(auto a:l[i])
        DFS_helper(a,final,visited);
      final.push(i);

    }
  }



  void DFS()
  {
    vector<int> visited(V,0); //to keep track of visited vertex
    
    for(int i=0;i<V;i++)
    {
      DFS_helper(i,final,visited);
    }
  }

  void reverse()
  {
  	list<int> *clone=new list<int>[V];
  	for(int i=0;i<V;i++)
  	{
  		for(auto a:l[i])
  			clone[a].push_back(i);
  	}
  	l = clone;
  }



  void component_detector(int i,vector<int> &visited)
 {
 	if(visited[i]!=1)
    {
      visited[i]=1;
      
      for(auto a:l[i])
        DFS_helper(a,final,visited);
    }
 	
 }


 int DFS_final()
 {
 	int c=0;
	vector<int> visited(V,0); //to keep track of visited vertex
    while(!final.empty())
 	{
 		int a=final.top();
 		final.pop();
 		if(visited[a]==0)
 		{
 			c++;
 		  component_detector(a,visited);

 		}

 	}
 	return c;

 }

 

};



int main()
{
	
	int e,v,a,b;
	cin>>v>>e;
	Graph g(v);
	while(e--)
	{
		cin>>a>>b;
		g.addnode(a,b);
	}
	g.DFS();
	g.reverse();
	cout<<g.DFS_final();
  
 	return 0;
}
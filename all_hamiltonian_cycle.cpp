#include<iostream>
#include<list>
#include<queue>
#include<map>
#include<stack>
#include<vector>
using namespace std;

int flag=0;

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


  void print_path(vector<int> & path)
  {
    for(auto a : path)
      cout<<a<<" ";
    cout<<"\n";
    flag=1;
  }


  void hamiltonian(vector<int> &path,vector<int> &visited)
  {
    if(path.size()==visited.size())
    {
      print_path(path);
      return ;

    }
    int a = path.back();
    for(int b : l[a])
    {
      if(visited[b]==false)
      {
        visited[b]=true;
        path.push_back(b);
        hamiltonian(path,visited);
         
        path.pop_back();
        visited[b]=false;
      }
    }
  }

};



int main()
{
  int v,e,a,b;
  cin>>v>>e;
  Graph g(v);
  while(e--)
  {
    cin>>a>>b;
    g.addnode(a,b);
  }
 vector<int> path;
 vector<int> visited(v);
 cout<<"enter the starting vertex";
 cin>>a;
 path.push_back(a);
 visited[a]=true;
 g.hamiltonian(path,visited);
 if(!flag)
  cout<<"cycle does not exist";

 return 0;
}
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void _ts(int v, bool visited[], stack<int> st, vector< vector<int> > graph){
	visited[v] = true;

	// go to all verices adjacent to this one
	for(int w=0;w<graph[v].size();w++){
		int new_node = graph[v][w];
		if(!visited[new_node]) _ts(new_node, visited, st, graph);
	}

	st.push(v);
}

void topological_sort(vector< vector<int> > graph){
	int vetices = graph.size();
	stack<int> st;
	
	// mark all vertices as not visited
	bool *visited = new bool[vetices];
	for(int i=0;i<vertices;i++) visited[i] = false;

	// call helper function to store topological sort
	// starting from all vertices one by one
	for(int i=0;i<vertices;i++){
		if(!visited[i]) _ts(i, visited, st, graph);
	}

	while(!st.empty()){
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}
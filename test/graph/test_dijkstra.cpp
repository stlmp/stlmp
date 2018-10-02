#include "gtest/gtest.h"
#include "djikstra_shortest_path.hpp"

void print_path(char, map<char, int>);

int main(){
	int n=5;							// number of nodes in graph
	char s='A';							// source node
	vector<vector<int> > graph;			//  directed graph
	map<char,int> paths;				//  nodes with their distances from source

	/*	Define graph like below
			A  B  C  D  E
		A	0  10  0  0  5
		B	0  0  1  0  2  
		C	0  0  0  4  0  
		D	7  0  6  0  0  
		E	0  3  9  2  0  
	*/
	vector<int> x={0, 10, 0, 0, 5};
	graph.push_back(x);
	x = {0, 0, 1, 0, 2};
	graph.push_back(x);
	x = {0, 0, 0, 4, 0};
	graph.push_back(x);
	x = {7, 0, 6, 0, 0};
	graph.push_back(x);
	x = {0, 3, 9, 2, 0};
	graph.push_back(x);

	paths = dijkstra_shortest_path(s, graph);
	print_path(s, paths);
	return 0;
}

void print_path(char s, map<char, int> s_path)
{	for(int i=0;i<s_path.size();i++)
		cout<<"\n"<<(char)('A'+i)<<" : "<<s_path[(char)('A'+i)];
	}


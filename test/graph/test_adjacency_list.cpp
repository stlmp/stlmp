#include "gtest/gtest.h"
#include "adjacency_list.hpp"
#include "topological_sort.hpp"
#include <iostream>
#include <vector>

using namespace std;

TEST(graph_adjacency_list, normal){
	int vertices[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	graph_al<int> *g = new graph_al<int>(vertices, (int)(sizeof(vertices) / sizeof(vertices[0])));
	g->connect_both_sides(0, 5);
	g->connect_both_sides(1, 5);
	g->connect_both_sides(7, 2);
	g->connect_both_sides(7, 3);
	g->connect_both_sides(1, 2);
	//g->print_graph();
	EXPECT_TRUE(g->connected(1, 0));
	EXPECT_TRUE(g->connected(3, 0));
	EXPECT_TRUE(g->connected(3, 2));
	EXPECT_EQ(g->connected_components(), 4);
}

TEST(graph_adjacency_list, topological_sort){
	int vertices[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector< vector<int> > graph((int)(sizeof(vertices) / sizeof(vertices[0])));
	graph[0].push_back(1);
	graph[1].push_back(2);
	graph[2].push_back(3);
	graph[3].push_back(4);
	graph[4].push_back(5);
	graph[5].push_back(6);
	graph[6].push_back(7);
	graph[7].push_back(8);

	stack<int> sorted_graph = topological_sort(graph);
	EXPECT_EQ(sorted_graph.top(), 0);
	sorted_graph.pop();
	EXPECT_EQ(sorted_graph.top(), 1);
	sorted_graph.pop();
	EXPECT_EQ(sorted_graph.top(), 2);
	sorted_graph.pop();
	EXPECT_EQ(sorted_graph.top(), 3);
	sorted_graph.pop();
	EXPECT_EQ(sorted_graph.top(), 4);
	sorted_graph.pop();
	EXPECT_EQ(sorted_graph.top(), 5);
	sorted_graph.pop();
	EXPECT_EQ(sorted_graph.top(), 6);
	sorted_graph.pop();
	EXPECT_EQ(sorted_graph.top(), 7);
	sorted_graph.pop();
	EXPECT_EQ(sorted_graph.top(), 8);
	sorted_graph.pop();
}


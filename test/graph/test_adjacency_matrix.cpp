#include "gtest/gtest.h"
#include "adjacency_matrix.hpp"
#include <iostream>

using namespace std;

TEST(graph_adjacency_matrix, all_tests){
	int vertices[] = {0, 1, 2, 3, 4, 5, 6, 7,8};
	graph_am<int> *g = new graph_am<int>(vertices, (int)(sizeof(vertices) / sizeof(vertices[0])));
	g->connect_both_sides(0, 5);
	g->connect_both_sides(1, 5);
	g->connect_both_sides(7, 2);
	g->connect_both_sides(7, 3);
	g->connect_both_sides(1, 2);
	ASSERT_TRUE(g->connected(1, 0));
	ASSERT_TRUE(g->connected(3, 0));
	ASSERT_TRUE(g->connected(3, 2));
}

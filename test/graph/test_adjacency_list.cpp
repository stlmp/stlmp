#include <vector>
#include <cassert>
#include "stlmp.h"

using namespace std;
using namespace stlmp::Graph::AdjacencyList;

void test_adjacency_list();

void test_topological_sort();

void test_unweighted_shortest_path();

int main() {
    test_adjacency_list();
    test_topological_sort();
    test_unweighted_shortest_path();
}

void test_adjacency_list() {
    int vertices[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    auto *g = new Graph<int>(vertices, (int) (sizeof(vertices) / sizeof(vertices[0])));
    g->connect_both_sides(0, 5);
    g->connect_both_sides(1, 5);
    g->connect_both_sides(7, 2);
    g->connect_both_sides(7, 3);
    g->connect_both_sides(1, 2);
    g->print_graph();
    assert(g->connected(1, 0));
    assert(g->connected(3, 0));
    assert(g->connected(3, 2));
    assert(g->connected_components() == 4);
}

void test_topological_sort() {
    int vertices[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Graph<int> graph(vertices, (int) (sizeof(vertices) / sizeof(vertices[0])));
    graph.connect(0, 1);
    graph.connect(1, 2);
    graph.connect(2, 3);
    graph.connect(3, 4);
    graph.connect(4, 5);
    graph.connect(5, 6);
    graph.connect(6, 7);
    graph.connect(7, 8);

    stlmp::Stack::Stack<int> sorted_graph = graph.topologicalSort();
    assert(sorted_graph.peek() == 0);
    sorted_graph.pop();
    assert(sorted_graph.peek() == 1);
    sorted_graph.pop();
    assert(sorted_graph.peek() == 2);
    sorted_graph.pop();
    assert(sorted_graph.peek() == 3);
    sorted_graph.pop();
    assert(sorted_graph.peek() == 4);
    sorted_graph.pop();
    assert(sorted_graph.peek() == 5);
    sorted_graph.pop();
    assert(sorted_graph.peek() == 6);
    sorted_graph.pop();
    assert(sorted_graph.peek() == 7);
    sorted_graph.pop();
    assert(sorted_graph.peek() == 8);
    sorted_graph.pop();
}

void test_unweighted_shortest_path() {
    int vertices[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Graph<int> graph(vertices, (int) (sizeof(vertices) / sizeof(vertices[0])));
    graph.connect(0, 1);
    graph.connect(1, 2);
    graph.connect(2, 3);
    graph.connect(3, 4);
    graph.connect(4, 5);
    graph.connect(5, 6);
    graph.connect(6, 7);
    graph.connect(7, 8);

    std::pair<std::vector<int>, std::vector<int> > pr = graph.shortestPathFromVertex(0);
    std::vector<int> distance = pr.first, path = pr.second;
    assert(distance.size() == path.size());
    cout << "vertex | distance | path (prev node) " << endl;
    for (int i = 0; i < distance.size(); i++) {
        cout << "   " << i << "        " << distance[i] << "        " << path[i] << endl;
        assert(i == distance[i]);
        if (i != 0) assert(i == path[i] + 1);
    }
}

// TODO: all below
/*
TEST(graph_adjacency_list, weighted_shortest_path_dijkstra){
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

	pair< vector<int>, vector<int> > pr = unweighted_shortest_path(graph, 0);
	std::vector<int> distance = pr.first, path = pr.second;
	ASSERT_EQ(distance.size(), path.size());
	cout << "vertex | distance | path (prev node) " << endl;
	for(int i = 0; i < distance.size(); i++){
		cout << "   " << i << "        " << distance[i] << "        " << path[i] << endl;
		assert(i, distance[i]);
		if(i != 0) assert(i, path[i] + 1);
	}
}

TEST(graph_adjacency_list, weighted_shortest_path_bellman_ford){
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

	pair< vector<int>, vector<int> > pr = unweighted_shortest_path(graph, 0);
	std::vector<int> distance = pr.first, path = pr.second;
	ASSERT_EQ(distance.size(), path.size());
	cout << "vertex | distance | path (prev node) " << endl;
	for(int i = 0; i < distance.size(); i++){
		cout << "   " << i << "        " << distance[i] << "        " << path[i] << endl;
		assert(i, distance[i]);
		if(i != 0) assert(i, path[i] + 1);
	}
}

TEST(graph_adjacency_list, weighted_shortest_path_prims){
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

	pair< vector<int>, vector<int> > pr = unweighted_shortest_path(graph, 0);
	std::vector<int> distance = pr.first, path = pr.second;
	ASSERT_EQ(distance.size(), path.size());
	cout << "vertex | distance | path (prev node) " << endl;
	for(int i = 0; i < distance.size(); i++){
		cout << "   " << i << "        " << distance[i] << "        " << path[i] << endl;
		assert(i, distance[i]);
		if(i != 0) assert(i, path[i] + 1);
	}
}
*/

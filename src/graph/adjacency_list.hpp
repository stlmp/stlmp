#include <iostream>
#include <vector>
#include <map>
#include "stlmp.h"
#include <algorithm>

using namespace stlmp::Queue;
using namespace stlmp::Graph::AdjacencyList;
using namespace stlmp::Stack;

template<typename T>
int Graph<T>::connected_components() {
    for (int i = 0; i < count; i++) visited[i] = false;
    int components = 0;
    for (int i = 0; i < count; i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i);
            components++;
        }
    }
    return components;
}

template<typename T>
void Graph<T>::print_graph() {
    cout << "Printing adjacency list of graph:" << endl;
    for (int i = 0; i < count; i++) {
        vector<int> v = connections[i];
        cout << "vertices connected to " << i << ":" << endl;
        for (int j = 0; j < v.size(); j++) {
            cout << connections[i][j] << " ";
        }
        cout << endl;
    }
}

template<typename T>
bool Graph<T>::connected(int i, int j) {
    return bfs(i, j);
}

template<typename T>
void Graph<T>::dfs(int i) {
    for (int j = 0; j < connections[i].size(); j++) {
        if (!visited[connections[i][j]]) {
            visited[connections[i][j]] = true;
            dfs(connections[i][j]);
        }
    }
}

template<typename T>
bool Graph<T>::bfs(int i, int j) {
    auto *q = new Queue::Queue<int>();
    // else, try searching though the connections
    for (int w = 0; w < this->count; w++) visited[w] = false;
    q->push(i);
    visited[i] = true;
    while (q->size) {
        int v = q->pop();
        for (int w = 0; w < connections[v].size(); w++) {
            if (!visited[connections[v][w]]) {
                if (connections[v][w] == j) return true;
                q->push(connections[v][w]);
                visited[connections[v][w]] = true;
            }
        }
    }
    return false;
}

template<typename T>
bool Graph<T>::contains(vector<int> v, int n) {
    return find(v.begin(), v.end(), n) != v.end();
}

template<typename T>
void Graph<T>::connect_both_sides(int i, int j) {
    connect(i, j);
    connect(j, i);
}

template<typename T>
void Graph<T>::connect(int i, int j) {
    connections[i].push_back(j);
}

template<typename T>
Graph<T>::Graph(T *vertices, int count) : count(count), visited(new bool[count]) {
    for (int i = 0; i < count; i++) {
        this->vertices.push_back(vertices[i]);
    }
}

/**
 * Topological sorting
 * */
// util function
template<class T>
void Graph<T>::topologicalSortUtil(int v, bool *visited, Stack::Stack<int> *st) {
    visited[v] = true;

    // go to all vertices adjacent to this one
    for (int w = 0; w < connections[v].size(); w++) {
        int new_node = connections[v][w];
        if (!visited[new_node]) topologicalSortUtil(new_node, visited, st);
    }

    st->push(v);
}

template<class T>
Stack<T> Graph<T>::topologicalSort() {
    Stack::Stack<int> st;

    // mark all vertices as not visited
    bool *visited = new bool[vertices.size()];
    for (int i = 0; i < vertices.size(); i++) visited[i] = false;

    // call helper function to store topological sort
    // starting from all vertices one by one
    for (int i = 0; i < vertices.size(); i++) {
        if (!visited[i]) topologicalSortUtil(i, visited, &st);
    }

    Stack::Stack<int> st2;
    st2 = st;

    cout << "Printing graph after topological sort: " << endl;
    while (!st.empty()) {
        cout << st.peek() << " ";
        st.pop();
    }
    cout << endl;

    return st2;
}

/*
 * Shortest path in Unweighted graph
 */
template<class T>
std::pair< vector<int>, vector<int> > Graph<T>::shortestPathFromVertex(int s){
    std::vector<int> distance(connections.size(), -1);
    std::vector<int> path(connections.size());
    Queue::Queue<int> q;
    int v, w;
    q.push(s);
    distance[s] = 0;

    while(q.size) {
        v = q.peek();
        q.pop();
        for(int k = 0; k < connections[v].size(); k++){
            w = connections[v][k];
            if(distance[w] == -1){
                distance[w] = distance[v] + 1;
                path[w] = v;
                q.push(w);
            }
        }
    }
    return std::make_pair(distance, path);
}


#include <iostream>
#include <vector>
#include <map>
#include "stlmp.h"
#include <algorithm>

using namespace stlmp::Queue;
using namespace stlmp::Graph::AdjacencyList;

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

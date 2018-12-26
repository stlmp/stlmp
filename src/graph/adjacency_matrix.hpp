#include "stlmp.h"

using namespace stlmp::Graph::AdjacencyMatrix;
using namespace stlmp::Queue;

template<typename T>
void stlmp::Graph::AdjacencyMatrix::Graph<T>::connect_both_sides(int i, int j) {
    this->connect(i, j);
    this->connect(j, i);
}

template<typename T>
bool stlmp::Graph::AdjacencyMatrix::Graph<T>::bfs(int i, int j) {
    auto *q = new Queue::Queue<int>();
    if (connections[i][j]) return true;
    // else, try searching though the connections
    for (int w = 0; w < this->count; w++) visited[w] = false;
    q->push(i);
    visited[i] = true;
    while (q->size) {
        int v = q->pop();
        for (int w = 0; w < this->count; w++) {
            if (!visited[w] && connections[v][w]) {
                if (w == j) return true;
                q->push(w);
                visited[w] = true;
            }
        }
    }
    return false;
}

template<typename T>
void stlmp::Graph::AdjacencyMatrix::Graph<T>::dfs(int i) {
    for (int j = 0; j < count; j++) {
        if (!visited[j] && connections[i][j]) {
            visited[j] = true;
            this->dfs(j);
        }
    }
}

template<typename T>
bool stlmp::Graph::AdjacencyMatrix::Graph<T>::connected(int i, int j) {
    return this->bfs(i, j);
}

template<typename T>
int stlmp::Graph::AdjacencyMatrix::Graph<T>::connected_components() {
    for (int i = 0; i < count; i++) visited[i] = false;
    int components = 0;
    for (int i = 0; i < count; i++) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }
    return components;
}

template<typename T>
void stlmp::Graph::AdjacencyMatrix::Graph<T>::connect(int i, int j) {
    connections[i][j] = true;
}

template<typename T>
stlmp::Graph::AdjacencyMatrix::Graph<T>::Graph(T *vertices, int count) : count(count), vertices(new T[count]),
                                                                         visited(new bool[count]) {
    connections = new bool *[count];
    for (int i = 0; i < count; i++) {
        connections[i] = new bool[count];
    }
    for (int i = 0; i < count; i++) {
        this->vertices[i] = vertices[i];
        for (int j = 0; j < count; j++) {
            connections[i][j] = (i == j);
        }
    }
}

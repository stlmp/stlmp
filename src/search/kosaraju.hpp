#include <iostream>
#include <stack>

using namespace std;
const int _max = 4000;
int n; // number of vertices
stack<int> S;
bool inStack[_max];

/*  Adj matrix:
    adj[u][v] = 0 <=> no edge to connect u and v
    adj[u][v] != 0 <=> there is an edge to connect u and v
*/ 
int adj[_max][_max];
char color[_max];

int not_in_stack() {
    for (int i = 1; i <= n; ++i) {
        if (!inStack[i]) {
            return i;
        }
    }
    return -1;
}

void dfs(int v) {
    color[v] = 'g'; // gray = being processed
    for (int u = 1; u <= n; ++u) {
        if (adj[v][u]) {
            // if we got a vertex
            if (color[u] == 'w') {
                dfs(u);
            }
        }
    }
    S.push(v);
    inStack[v] = true;
    color[v] = 'b'; // black = processes
}

void dfsT(int v) {
    // dfs on the transpose graph
    color[v] = 'g';
    printf("%d ", v);
    for (int u = 1; u <= n; ++u) {
        if (adj[u][v]) {
            if (color[u] == 'w') {
                dfsT(u);
            }
        }
    }
    color[v] = 'b';

    // Remove v from graph:
    for (int i = 1; i <= n; ++i) {
        adj[v][i] = 0;
        adj[i][v] = 0;
    }
}

void kosaraju() {
    for (int i = 1; i <= n; ++i) {
        color[i] = 'w'; // white = before any processing
        inStack[i] = false;
    }

    int v;
    while ((v = not_in_stack()) != -1) {
        dfs(v);
    }
    for (int i = 1; i <= n; ++i) {
        color[i] = 'w'; // white
    }
    printf("Hard conex components: \n");
    while (!S.empty()) {
        v = S.top();
        S.pop();
        inStack[v] = false;
        if (color[v] != 'b') {
            dfsT(v);
            printf("\n");
        }
    }
}
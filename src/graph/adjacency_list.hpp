#include <iostream>
#include <vector>
#include "../queue/queue.hpp"
using namespace std;

template<typename T>
class graph_al {
private:
	int count;
	map< int, vector<T> > connections;
	vector<T> vertices;
	bool *visited;
public:
	graph_al(T vertices[], int count) : count(count), visited(new bool[count]) {
		for(int i=0;i<count;i++){
			this->vertices.push_back(vertices[i]);
		}
	}

	void connect(int i, int j){
		connections[i].push_back(j);
	}

	void connect_both_sides(int i, int j){
		connect(i, j);
		connect(j, i);
	}

	bool contains(vector<int> v, int n){
		return find(v.begin(), v.end(), n) != v.end();
	}

	bool bfs(int i, int j){
		queuemp<int> *q = new queuemp<int>();
		// else, try seraching though the connections
		for(int w=0;w<this->count;w++) visited[w] = false;
		q->push(i);
		visited[i] = true;
		while(q->size){
			int v = q->pop();
			for(int w = 0; w < connections[v].size();w++){
				if(!visited[w]){
					if(connections[v][w] == v) return true;
					q->push(connections[v][w]);
					visited[w] = true;
				}
			}
		}
		return false;
	}

	void dfs(int i){
		for(int j=0;j<connections[i].size();j++){
			if(!visited[connections[i][j]]){
				visited[connections[i][j]] = true;
				dfs(j);
			}
		}
	}

	// check if the vertices at i and j are connected.
	bool connected(int i, int j){
		return bfs(i, j);
	}

	int connected_components(){
		for(int i=0;i<count;i++) visited[i] = false;
		int components = 0;
		for(int i=0;i<count;i++){
			if(!visited[i]){
				dfs(i);
				components++;
			}
		}
		return components;
	}
};

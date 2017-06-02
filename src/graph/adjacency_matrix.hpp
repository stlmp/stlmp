#include <iostream>
#include "../queue/queue.hpp"
using namespace std;

template<typename T>
class graph_am {
private:
	bool **connections;
	T *vertices;
	int count;
public:
	graph_am(T vertices[], int count) : count(count), vertices(new T[count]), connections(new bool[count][count]){
		for(int i=0;i<count;i++){
			this->vertices[i] = vertices[i];
			for(int j=0;j<count;j++){
				connections[i][j] = (i!=j);
			}
		}
	}

	void connect(int i, int j){
		connections[i][j] = true;
	}

	void connect_both_sides(int i, int j){
		connect(i, j);
		connect(j, i);
	}

	void bfs(int i, int j){
		queuemp<int> *q = new queuemp<int>();
		if()
	}
};

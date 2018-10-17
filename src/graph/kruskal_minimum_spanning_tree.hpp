//
// Created by brand-temp on 8/10/2018.
//

// Whole thing needs a redesign
// return vector of edges
// return total weight and vecotr of edges?
// yikes...
// Ideas.....
/*
1. send in pointer, return weight of mst, and the thing at the pointer is changed to the tree
2. return pair of totaly weight then edges
*/

#include <iostream>
#include <vector>

using namespace std;


/**
 * kruskal_minimum_spanning_tree - implements the Kruskal algorithm
 * @tparam T - The label type for each vertex in the graph, i.e. int or string
 * @param v - vector of Ts representing each vertex in the graph
 * @param e - vector of pairs of integers and T pairs representing each edge in the graph
 * @return a vector of edges and their weights
 */

template<class T>
struct edge {
    T start_point;
    T end_point;
    int weight;
    edge(T s, T e, int w) : start_point(s), end_point(e), weight(w) { }
    bool operator<(const edge &rhs) const {
        return weight < rhs.weight;
    }
};
template<class T>
pair<int, vector<edge<T>>> kruskal_minimum_spanning_tree(vector<T> v, vector<edge<T>> e) {
    // make vector of "trees"
    vector<vector<T>> trees;
    vector<edge<T>> mst;
    int weight = 0;
    for(T vertex : v) {
        vector<T> tree;
        tree.push_back(vertex);
        trees.push_back(tree);
    }
    sort(e.rbegin(), e.rend());
    while(e.size() > 0) {
        edge<T> curr = e.back();
        e.pop_back();

        T a = curr.start_point, b = curr.end_point;
        int a_index = -1, b_index = -1;
        for(int i = 0; i < trees.size(); i++) {
            vector<T> tree = trees[i];
            for(T label : tree) {
                if (label == a)
                    a_index = i;
                if (label == b)
                    b_index = i;
            }
        }
        if (a_index == -1 || b_index == -1)
            continue;
        if(a_index == b_index)
            continue;
        weight += curr.weight;
        mst.push_back(curr);

        trees[a_index].insert(trees[a_index].end(), trees[b_index].begin(), trees[b_index].end());
        trees.erase(trees.begin() + b_index);
    }
    pair<int, vector<edge<T>>> toRet;
    if(trees.size() > 1) {
        toRet.first = 0;
        cout << "This graph doesn't appear to be fully connected. All edges have been exhausted, "
                "but there are still unconnected vertices." << endl;
        return toRet;
    }
    toRet.first = weight;
    toRet.second = mst;
    return toRet;
}

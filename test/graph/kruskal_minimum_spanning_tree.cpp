#include "gtest/gtest.h"
#include "kruskal_minimum_spanning_tree.hpp"
#include <iostream>

using namespace std;

TEST(kruskal_minimum_spanning_tree, all_tests) {
    vector<char> vertex;
    vertex.push_back('A');
    vertex.push_back('B');
    vertex.push_back('C');
    vertex.push_back('D');
    vertex.push_back('E');

    vector<edge<char>> edges;
    edges.push_back(edge<char>('A', 'B', 1));
    edges.push_back(edge<char>('A', 'C', 7));
    edges.push_back(edge<char>('A', 'D', 6));
    edges.push_back(edge<char>('B', 'E', 4));
    edges.push_back(edge<char>('C', 'E', 1));
    edges.push_back(edge<char>('D', 'E', 1));



    pair<int, vector<edge<char>>> returnTree = kruskal_minimum_spanning_tree(vertex, edges);

    cout << "-------------------\nKRUSKAL 1\n-------------------" << endl;
    cout << "Expected weight was 7, actual weight was: " << returnTree.first << endl;
    cout << "Edges were: " << endl;
    for(edge<char> e: returnTree.second) {
        cout << e.start_point << " to " << e.end_point << " with weight: " << e.weight << endl;
    }

    ASSERT_TRUE(returnTree.first == 7);

    vertex.push_back('F');
    vertex.push_back('G');

    edges.push_back(edge<char>('G', 'D', 3));
    edges.push_back(edge<char>('G', 'A', 4));
    edges.push_back(edge<char>('F', 'C', 2));
    edges.push_back(edge<char>('F', 'G', 1));

    returnTree = kruskal_minimum_spanning_tree(vertex, edges);

    cout << "-------------------\nKRUSKAL 2\n-------------------" << endl;
    cout << "Expected weight was 10, actual weight was: " << returnTree.first << endl;
    cout << "Edges were: " << endl;
    for(edge<char> e: returnTree.second) {
        cout << e.start_point << " to " << e.end_point << " with weight: " << e.weight << endl;
    }

    ASSERT_TRUE(returnTree.first == 10);

    returnTree = kruskal_minimum_spanning_tree(vertex, edges);

    edges.pop_back();
    edges.push_back(edge<char>('D', 'B', -10));

    returnTree = kruskal_minimum_spanning_tree(vertex, edges);

    cout << "-------------------\nKRUSKAL 3\n-------------------" << endl;
    cout << "Expected weight was -2, actual weight was: " << returnTree.first << endl;
    cout << "Edges were: " << endl;
    for(edge<char> e: returnTree.second) {
        cout << e.start_point << " to " << e.end_point << " with weight: " << e.weight << endl;
    }

    ASSERT_TRUE(returnTree.first == -2);

    vertex.push_back('H');

    returnTree = kruskal_minimum_spanning_tree(vertex, edges);

    cout << "-------------------\nKRUSKAL 4\n-------------------" << endl;
    cout << "Expected weight was 0, actual weight was: " << returnTree.first << endl;
    cout << "Edges were: " << endl;
    for(edge<char> e: returnTree.second) {
        cout << e.start_point << " to " << e.end_point << " with weight: " << e.weight << endl;
    }

    ASSERT_TRUE(returnTree.first == 0 && returnTree.second.size() == 0);
}

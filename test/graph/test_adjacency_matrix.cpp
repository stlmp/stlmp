#include <cassert>
#include "stlmp.h"

using namespace stlmp::Graph::AdjacencyMatrix;

int main() {
    int vertices[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    auto g = new stlmp::Graph::AdjacencyMatrix::Graph<int>(vertices, (int) (sizeof(vertices) / sizeof(vertices[0])));
    g->connect_both_sides(0, 5);
    g->connect_both_sides(1, 5);
    g->connect_both_sides(7, 2);
    g->connect_both_sides(7, 3);
    g->connect_both_sides(1, 2);
    assert(g->connected(1, 0));
    assert(g->connected(3, 0));
    assert(g->connected(3, 2));
    assert(g->connected_components() == 4);
}

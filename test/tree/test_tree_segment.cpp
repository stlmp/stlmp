//
// Created by manparvesh on 12/26/18.
//
#include "stlmp.h"
using namespace stlmp::Tree;

int main() {
    int ar[] = {1, 2, 3, 4, 5};
    segment_tree *st = new segment_tree(ar, 5);
    st->print();
    st->update(0, 0);
    st->update(2, 4);
    st->print();
    ASSERT_EQ(st->get(0), 15);
    ASSERT_EQ(st->get_sum(0, 4), 15);
}


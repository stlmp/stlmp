//
// Created by manparvesh on 12/26/18.
//
#include <cassert>
#include "stlmp.h"

using namespace stlmp::Tree::SegmentTree;

int main() {
    int ar[] = {1, 2, 3, 4, 5};
    auto *st = new stlmp::Tree::SegmentTree::SegmentTree(ar, 5);
    st->print();
    st->update(0, 0);
    st->update(2, 4);
    st->print();
    assert(st->get(0) == 15);
    assert(st->get_sum(0, 4) == 15);
}


#include <cassert>
#include "stlmp.h"

int main() {
    auto *ds = new stlmp::DisjointSet::DisjointSet(10);

    ds->merge(4, 5);
    ds->merge(1, 2);
    ds->merge(2, 4);
    assert(ds->connected(1, 5));
    assert(!ds->connected(1, 3));
}

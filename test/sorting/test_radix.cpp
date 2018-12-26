#include <cassert>
#include "stlmp.h"

int main() {
    int foo[] = {1, 3, 2, 5, 4};
    stlmp::Sorting::RadixSort<int> sort;
    sort.sort(5, foo);
    for (int i = 0; i < 5; ++i) {
        assert(foo[i] == i + 1);
    }
}
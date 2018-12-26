#include <cassert>
#include "stlmp.h"

using namespace stlmp::Stack;

int main() {
    int foo[] = {1, 2, 3, 4, 5};
    auto *st = new Stack<int>(6);
    for (int element : foo) {
        st->push(element);
    }
    st->print();
    assert(st->getSize() == 5);
    assert(st->getCapacity() == 6);
    assert(st->pop() == 5);
    st->print();
    assert(st->pop() == 4);
    st->print();
    assert(st->peek() == 3);
    assert(st->pop() == 3);
    st->print();
    assert(st->pop() == 2);
    st->print();
    assert(st->pop() == 1);
    st->print();
    assert(st->pop() == '\0');
    st->print();
}
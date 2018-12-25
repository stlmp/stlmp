#include <cassert>
#include "stlmp.h"

int main() {
    int foo[] = {1, 2, 3, 4, 5};
    auto *q = new stlmp::Queue::Queue<int>();
    for (int element : foo) {
        q->push(element);
    }
    q->print();
    assert(get_size(q) == 5);
    assert(q->pop() == 1);
    q->print();
    assert(q->pop() == 2);
    q->print();
    assert(q->pop() == 3);
    assert(q->peek() == 5);
    q->print();
    assert(q->pop() == 4);
    q->print();
    assert(q->pop() == 5);
    q->print();
    assert(q->pop() == '\0');
    q->print();
}
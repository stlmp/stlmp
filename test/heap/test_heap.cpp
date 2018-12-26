#include <cassert>
#include "stlmp.h"

using namespace stlmp::Heap;

int main(){
    auto *h = new Heap<int>(10, 1);
	assert(h->is_empty());
	h->insert(1);
	h->insert(2);
	h->insert(3);
	h->insert(4);
	h->print();
	assert(h->get_size() == 4);
	assert(h->get_capacity() == 10);
	assert(h->get_type() == 1);
	assert(h->get_max() == 4);
	assert(!h->is_full());
	assert(!h->is_empty());
	assert(h->is_heap());

	int arr[] = {1, 2, 3, 4, 5, 6};
    auto *h2 = new Heap<int>(arr, 6, 1);
	h2->print();
	assert(h2->is_heap());
}

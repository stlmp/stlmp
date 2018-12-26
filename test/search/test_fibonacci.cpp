#include <cassert>
#include "stlmp.h"

using namespace stlmp::Search;

int main() {
	int foo[] = {1, 2, 3, 4, 5};
	FibonacciSearch<int> binarySearch;
	int pos = binarySearch.search(5, foo, -3);
	assert(pos == -1);
	pos = binarySearch.search(5, foo, 1);
	assert(pos == 0);
	pos = binarySearch.search(5, foo, 2);
	assert(pos == 1);
	pos = binarySearch.search(5, foo, 3);
	assert(pos == 2);
	pos = binarySearch.search(5, foo, 4);
	assert(pos == 3);
	pos = binarySearch.search(5, foo, 5);
	assert(pos == 4);
}
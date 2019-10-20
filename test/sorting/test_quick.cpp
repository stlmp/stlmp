#include <cassert>
#include "stlmp.h"


int main() {
	int foo[] = {1, 3, 2, 5, 4};
	stlmp::Sorting::QuickSort<int> sort;
	sort.sort(5, foo);
	for (int i = 0; i < 4; ++i) {
		assert(foo[i] <= foo[i + 1]);
	}
}

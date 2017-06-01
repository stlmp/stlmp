#include "gtest/gtest.h"
#include "heap.hpp"
#include <iostream>

using namespace std;

TEST(heap, all_tests){
	heap<int> *h = new heap<int>(10, 1);
	int arr[] = {1, 2, 3, 4, 5, 6};
	heap<int> *h2 = new heap<int>(arr, 6, 1);
	h2->print();
	ASSERT_TRUE(h2->is_heap());
}

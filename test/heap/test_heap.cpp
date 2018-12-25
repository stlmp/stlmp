#include "gtest/gtest.h"
#include "heap.hpp"
#include <iostream>

using namespace std;

TEST(heap, all_tests){
	heap<int> *h = new heap<int>(10, 1);
	ASSERT_TRUE(h->is_empty());
	h->insert(1);
	h->insert(2);
	h->insert(3);
	h->insert(4);
	h->print();
	ASSERT_EQ(h->get_size(), 4);
	ASSERT_EQ(h->get_capacity(), 10);
	ASSERT_EQ(h->get_type(), 1);
	ASSERT_EQ(h->get_max(), 4);
	ASSERT_FALSE(h->is_full());
	ASSERT_FALSE(h->is_empty());
	ASSERT_TRUE(h->is_heap());

	int arr[] = {1, 2, 3, 4, 5, 6};
	heap<int> *h2 = new heap<int>(arr, 6, 1);
	h2->print();
	ASSERT_TRUE(h2->is_heap());
}

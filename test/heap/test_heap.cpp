#include "gtest/gtest.h"
#include "heap.hpp"
#include <iostream>

using namespace std;

TEST(heap, all_tests){
	heap<int> *h = new heap<int>(10, 1);
}

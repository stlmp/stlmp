#include "gtest/gtest.h"
#include "disjoint_set.hpp"
#include <iostream>

using namespace std;

TEST(disjoint_set, all_tests){
	disjoint_set *ds = new disjoint_set(10);

	ds->merge(4, 5);
	ds->merge(1, 2);
	ds->merge(2, 4);
	ASSERT_TRUE(ds->connected(1, 5));
	ASSERT_FALSE(ds->connected(1, 3));
}

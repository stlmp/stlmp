#include "gtest/gtest.h"
#include "binary.hpp"
#include <bits/stdc++.h>
using namespace std;

TEST(insertion_sort, all_tests){
	int foo[] = {1, 3, 2, 5, 4};
	int pos = binary_search(5, foo,3);
	ASSERT_EQ(pos, 1);
}
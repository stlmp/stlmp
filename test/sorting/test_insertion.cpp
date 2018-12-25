#include "gtest/gtest.h"
#include "insertion.hpp"
#include <bits/stdc++.h>
using namespace std;

TEST(insertion_sort, all_tests){
	int foo[] = {1, 3, 2, 5, 4};
	insertion_sort(5, foo);
	ASSERT_EQ(foo[4], 5);
}
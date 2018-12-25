#include "gtest/gtest.h"
#include "merge.hpp"
#include <bits/stdc++.h>
using namespace std;

TEST(merge_sort, all_tests){
	int foo[] = {1, 3, 2, 5, 4};
	merge_sort(5, foo);
	ASSERT_EQ(foo[4], 5);
}
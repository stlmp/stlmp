#include "gtest/gtest.h"
#include "quick.hpp"
#include <bits/stdc++.h>
using namespace std;

TEST(quick_sort, all_tests){
	int foo[] = {1, 3, 2, 5, 4};
	quick_sort(5, foo);
	ASSERT_EQ(foo[4], 5);
}
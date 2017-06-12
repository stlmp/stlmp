#include "gtest/gtest.h"
#include "bubble.hpp"
#include <bits/stdc++.h>
using namespace std;

TEST(bubble_sort, all_tests){
	int foo[] = {1, 3, 2, 5, 4};
	bubble_sort(5, foo);
	ASSERT_EQ(foo[4], 5);
}
#include "gtest/gtest.h"
#include "radix.hpp"
#include <bits/stdc++.h>
using namespace std;

TEST(radix_sort, all_tests){
	int foo[] = {12, 334, 220, 540, 4};
	radix_sort(5, foo);
	ASSERT_EQ(foo[4], 540);
}
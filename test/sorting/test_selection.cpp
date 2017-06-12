#include "gtest/gtest.h"
#include "selection.hpp"
#include <bits/stdc++.h>
using namespace std;

TEST(selection_sort, all_tests){
	int foo[] = {1, 3, 2, 5, 4};
	selection_sort(5, foo);
	ASSERT_EQ(foo[4], 5);
}
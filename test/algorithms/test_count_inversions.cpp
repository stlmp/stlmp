#include "gtest/gtest.h"
#include "inversions.hpp"
#include <iostream>

using namespace std;

TEST(count_inversions, all_tests){
	int arr[] = {9, 3, 10, 11, 1};
    int arr_size = 5;
    int ans = count_inversions(arr,arr_size);

    ASSERT_EQ(ans, 5);
}

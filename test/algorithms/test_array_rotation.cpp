#include "gtest/gtest.h"
#include "array_roatation.hpp"
#include <iostream>

using namespace std;

TEST(reverse_array, all_tests){
	
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int d = 2;

	reverse_array(arr, d, n);

    	ASSERT_EQ(arr[0], 3);
	ASSERT_EQ(arr[1], 4);
	ASSERT_EQ(arr[2], 5);
	ASSERT_EQ(arr[3], 6);
	ASSERT_EQ(arr[4], 7);
	ASSERT_EQ(arr[5], 1);
	ASSERT_EQ(arr[6], 2);

}
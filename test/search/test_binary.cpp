#include "gtest/gtest.h"
#include "binary.hpp"

using namespace std;

TEST(binary_search, all_tests){
	int foo[] = {1, 3, 2, 5, 4};
	int pos = binary_search(5, foo,3);
	ASSERT_EQ(pos, 1);
}
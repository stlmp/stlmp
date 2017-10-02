#include "gtest/gtest.h"
#include "fibonacci.hpp"

using namespace std;

TEST(fibonacci_search, all_tests)
{
	int foo[] = {1, 3, 2, 5, 4};
	int pos = fibonacci_search(5, foo,3);
	ASSERT_EQ(pos, 1);
}

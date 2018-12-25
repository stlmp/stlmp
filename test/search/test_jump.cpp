#include "gtest/gtest.h"
#include "jump.hpp"

using namespace std;

TEST(jump_search, all_tests)
{
	int foo[] = {1, 3, 2, 5, 4};
	int pos = jump_search(5, foo,3);
	ASSERT_EQ(pos, 1);
}

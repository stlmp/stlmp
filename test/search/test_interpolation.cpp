#include "gtest/gtest.h"
#include "interpolation.hpp"

using namespace std;

TEST(interpolation_search, all_tests)
{
    int foo[] = {1, 3, 2, 5, 4};
    int pos = interpolation_search(5, foo, 3);
    ASSERT_EQ(pos, 1);
}

#include "gtest/gtest.h"
#include "shell.hpp"
#include <bits/stdc++.h>
using namespace std;

TEST(shell_sort, all_tests){
    int foo[] = {1, 5, 2, 3, 4};
    shell_sort(5, foo);
    ASSERT_EQ(foo[4], 5);
}

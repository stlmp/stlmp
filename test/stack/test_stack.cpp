#include "gtest/gtest.h"
#include "stack.hpp"
#include <bits/stdc++.h>
using namespace std;

TEST(stack, all_tests){
	int foo[] = {1, 2, 3, 4, 5};
	stackmp<int> *st = new stackmp<int>(6); 
	for(int element : foo){
		st->push(element);
	}
	st->print();
	ASSERT_EQ(get_size(st), 5);
	ASSERT_EQ(get_capacity(st), 6);
	ASSERT_EQ(st->pop(), 5);
	st->print();
	ASSERT_EQ(st->pop(), 4);
	st->print();
	ASSERT_EQ(st->peek(), 3);
	ASSERT_EQ(st->pop(), 3);
	st->print();
	ASSERT_EQ(st->pop(), 2);
	st->print();
	ASSERT_EQ(st->pop(), 1);
	st->print();
	ASSERT_EQ(st->pop(), '\0');
	st->print();
}
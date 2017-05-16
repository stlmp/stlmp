#include "gtest/gtest.h"
#include "queue.hpp"
#include <bits/stdc++.h>
using namespace std;

TEST(queue, all_tests){
	int foo[] = {1, 2, 3, 4, 5};
	queuemp<int> *q = new queuemp<int>(); 
	for(int element : foo){
		q->push(element);
	}
	q->print();
	ASSERT_EQ(get_size(q), 5);
	ASSERT_EQ(q->pop(), 1);
	q->print();
	ASSERT_EQ(q->pop(), 2);
	q->print();
	ASSERT_EQ(q->pop(), 3);
	q->print();
	ASSERT_EQ(q->pop(), 4);
	q->print();
	ASSERT_EQ(q->pop(), 5);
	q->print();
	ASSERT_EQ(q->pop(), '\0');
	q->print();
}
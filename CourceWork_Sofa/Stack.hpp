#pragma once
#include <stack>

class Stack
{
	std::stack<int> s;

public:
	Stack();
	Stack(std::stack<int> s);
	Stack(int n, int min, int max);
	bool own(int v);
	int size();
	bool subset(const Stack &_s) const;
	bool quality(const Stack &_s);
	Stack union_set(const Stack &_s);
	Stack intersection_set(const Stack &_s);
	Stack difference_set(const Stack &_s);
	Stack symmetric_difference_set(const Stack &_s);
};
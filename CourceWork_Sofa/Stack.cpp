#include "Stack.hpp"

Stack::Stack() = default;

Stack::Stack(std::stack<int> s) : s(s) {}

Stack::Stack(int n, int min, int max)
{
	for (auto i = 0; i < n; ++i)
	{
		int ch;
		while (own(ch = min + min + rand() % (max - min)));
		s.emplace(ch);
	}
}

bool Stack::own(int v)
{
	for (auto t = s; !t.empty(); t.pop())
		if (t.top() == v)
			return true;

	return false;
}

int Stack::size()
{
	return s.size();
}

bool Stack::subset(const Stack &_s) const
{
	for (auto iter2 = _s.s, iter1 = s; !(iter2.empty() || iter1.empty()); iter2.pop())
	{
		if (iter2.top() == iter1.top())
			iter1.pop();
		else
			iter1 = s;

		if (iter1.empty())
			return true;
	}

	return false;
}

bool Stack::quality(const Stack &_s)
{
	return _s.subset(*this) && subset(_s);
}

Stack Stack::union_set(const Stack &_s)
{
	Stack new_stack = s;

	for (auto t = _s.s; !t.empty(); t.pop())
	{
		auto v = t.top();

		if (own(v))
			new_stack.s.emplace(v);
	}

	return new_stack;
}

Stack Stack::intersection_set(const Stack &_s)
{
	Stack new_stack;

	for (auto t = _s.s; !t.empty(); t.pop())
	{
		auto v = t.top();

		if (own(v))
			new_stack.s.emplace(v);
	}

	return new_stack;
}

Stack Stack::difference_set(const Stack &_s)
{
	Stack new_stack;

	for (auto t = _s.s; !t.empty(); t.pop())
	{
		auto v = t.top();

		if (!own(v))
			new_stack.s.emplace(v);
	}

	return new_stack;
}

Stack Stack::symmetric_difference_set(const Stack &_s)
{
	return intersection_set(_s).difference_set(union_set(_s));
}
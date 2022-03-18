#include "Set_4.hpp"

using namespace Set_4;

Set::Set(int count, int min, int max)
{
	for (auto i = 0; i < count; ++i)
		while (!add(min + min + rand() % (max - min)));
}

int Set::size()
{
	return lst.size();
}

bool Set::own(int val)
{
	for (auto iter : lst)
		if (iter == val)
			return true;

	return false;
}

bool Set::isEmpty()
{
	return lst.empty();
}

bool Set::add(int val)
{
	if (own(val))
		return false;

	lst.emplace_front(val);
	return true;
}

std::string Set::print(char sp)
{
	std::string out;

	for (auto iter : lst)
		out += std::to_string(iter) + sp;

	if (!out.empty())
		out.resize(out.size() - 1);

	return out;
}

bool Set::subset(const Set &set) const
{
	for (auto iter2 = set.lst.begin(), iter1 = lst.begin(); iter2 != set.lst.end() && iter1 != lst.end(); ++iter2)
		if ((iter1 = *iter2 == *iter1 ? ++iter1 : lst.begin()) == lst.end())
			return true;

	return false;
}

bool Set::quality(const Set &set)
{
	return set.subset(*this) && subset(set);
}

Set Set::union_set(const Set &set)
{
	Set new_set;

	for (auto iter : set.lst)
		new_set.add(iter);

	for (auto iter : lst)
		new_set.add(iter);

	return new_set;
}

Set Set::intersection_set(const Set &set)
{
	Set new_set;

	for (auto iter : set.lst)
		if (own(iter))
			new_set.add(iter);

	return new_set;
}

Set Set::difference_set(const Set &set)
{
	Set new_set;

	for (auto iter : set.lst)
		if (!own(iter))
			new_set.add(iter);

	return new_set;
}

Set Set::symmetric_difference_set(const Set &set)
{
	return intersection_set(set).difference_set(union_set(set));
}
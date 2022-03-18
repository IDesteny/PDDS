#include "Set_5.hpp"

using namespace Set_5;

Set::Set(int count, int min, int max)
{
	for (auto i = 0; i < count; ++i)
		while (!add(min + min + rand() % (max - min)));
}

int Set::size()
{
	return st.size();
}

bool Set::own(int val)
{
	return st.find(val) != st.end();
}

bool Set::isEmpty()
{
	return st.empty();
}

bool Set::add(int val)
{
	return st.emplace(val).second;
}

std::string Set::print(char sp)
{
	std::string out;
	std::for_each(st.begin(), st.end(), [&](int v) { out += std::to_string(v) + sp; });
	return out;
}

bool Set::subset(const Set &_st) const
{
	return std::includes(st.begin(), st.end(), _st.st.begin(), _st.st.end());
}

bool Set::quality(const Set &_st)
{
	return std::equal(st.begin(), st.end(), _st.st.begin());
}

Set Set::union_set(const Set &_st)
{
	Set new_set;
	std::set_union(st.begin(), st.end(), _st.st.begin(), _st.st.end(), std::inserter(new_set.st, new_set.st.begin()));
	return new_set;
}

Set Set::intersection_set(const Set &_st)
{
	Set new_set;
	std::set_intersection(st.begin(), st.end(), _st.st.begin(), _st.st.end(), std::inserter(new_set.st, new_set.st.begin()));
	return new_set;
}

Set Set::difference_set(const Set &_st)
{
	Set new_set;
	std::set_difference(st.begin(), st.end(), _st.st.begin(), _st.st.end(), std::inserter(new_set.st, new_set.st.begin()));
	return new_set;
}

Set Set::symmetric_difference_set(const Set &_st)
{
	Set new_set;
	std::set_symmetric_difference(st.begin(), st.end(), _st.st.begin(), _st.st.end(), std::inserter(new_set.st, new_set.st.begin()));
	return new_set;
}
#include "Set_3.hpp"

using namespace Set_3;

Set::Set(int count, int min, int max)
{
	for (auto i = 0; i < count; ++i)
		while (!add(min + min + rand() % (max - min)));
}

Set::Set(Set &&set) noexcept
{
	head = set.head;
	len = set.len;

	set.head = nullptr;
}

Set::~Set()
{
	while (head)
	{
		auto next_node = head->next;
		delete head;
		head = next_node;
	}
}

bool Set::own(int val) const
{
	for (auto iter = head; iter; iter = iter->next)
		if (iter->data == val)
			return true;

	return false;
}

bool Set::add(int val)
{
	if (own(val))
		return false;

	head = new Node { head, val };
	++len;
	return true;
}

bool Set::isEmpty()
{
	return !head;
}

int Set::size() const
{
	return len;
}

std::string Set::print(char sp)
{
	std::string dt;

	for (auto iter = head; iter; iter = iter->next)
		dt += std::to_string(iter->data) + sp;

	if (!dt.empty())
		dt.resize(dt.size() - 1);


	return dt;
}

bool Set::subset(const Set &set) const
{
	for (auto iter2 = set.head, iter1 = head; iter2 && iter1; iter2 = iter2->next)
		if (!(iter1 = iter2->data == iter1->data ? iter1->next : head))
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

	for (auto iter = set.head; iter; iter = iter->next)
		new_set.add(iter->data);

	for (auto iter = head; iter; iter = iter->next)
		new_set.add(iter->data);

	return new_set;
}

Set Set::intersection_set(const Set &set)
{
	Set new_set;

	for (auto iter1 = set.head; iter1; iter1 = iter1->next)
		if (own(iter1->data))
			new_set.add(iter1->data);

	return new_set;
}

Set Set::difference_set(const Set &set)
{
	Set new_set;

	for (auto iter1 = set.head; iter1; iter1 = iter1->next)
		if (!own(iter1->data))
			new_set.add(iter1->data);

	return new_set;
}

Set Set::symmetric_difference_set(const Set &set)
{
	return intersection_set(set).difference_set(union_set(set));
}
#include "Set_2.hpp"

// F1
Node *create_empty()
{
	return nullptr;
}

// F2
bool isEmpty(Node *set)
{
	return !set;
}

// F3
bool own(Node *set, int val)
{
	for (auto iter = set; iter; iter = iter->next)
		if (iter->data == val)
			return true;

	return false;
}

// F4
Node *add(Node *set, int val)
{
	if (own(set, val))
		return set;

	return new Node { set, val };
}

// F5
Node *create(int counter, int min, int max)
{
	auto set = create_empty();

	for (auto i = 0; i < counter; ++i)
	{
		auto old_head = set;
		while (old_head == (set = add(set, min + rand() % (max - min))));
	}

	return set;
}

// F6
int size(Node *set)
{
	auto counter = 0;
	for (auto iter = set; iter; iter = iter->next, ++counter);

	return counter;
}

// F7
std::string print(Node *set, char sp)
{
	std::string dt;

	for (auto iter = set; iter; iter = iter->next)
		dt += std::to_string(iter->data) + sp;

	if (!dt.empty())
		dt.resize(dt.size() - 1);

	return dt;
}

// F8
Node *delete_set(Node *set)
{
	while (set)
	{
		auto next_node = set->next;
		delete set;
		set = next_node;
	}

	return nullptr;
}

// F9
bool subset(Node *set1, Node *set2)
{
	for (auto iter2 = set2, iter1 = set1; iter2 && iter1; iter2 = iter2->next)
		if (!(iter1 = iter2->data == iter1->data ? iter1->next : set1))
			return true;

	return false;
}

// F10
bool quality(Node *set1, Node *set2)
{
	return subset(set2, set1) && subset(set1, set2);
}

// F11
Node *union_set(Node *set1, Node *set2)
{
	auto new_set = create_empty();

	for (auto iter = set1; iter; iter = iter->next)
		new_set = add(new_set, iter->data);

	for (auto iter = set2; iter; iter = iter->next)
		new_set = add(new_set, iter->data);

	return new_set;
}

// F12
Node *intersection_set(Node *set1, Node *set2)
{
	auto new_set = create_empty();

	for (auto iter1 = set1; iter1; iter1 = iter1->next)
		for (auto iter2 = set2; iter2; iter2 = iter2->next)
			if (iter1->data == iter2->data)
				new_set = add(new_set, iter1->data);

	return new_set;
}

// F13
Node *difference_set(Node *set1, Node *set2)
{
	auto new_set = create_empty();

	for (auto iter1 = set1; iter1; iter1 = iter1->next)
	{
		auto cmp = false;
		for (auto iter2 = set2; iter2; iter2 = iter2->next)
			if (iter1->data == iter2->data)
				cmp = true;
		if (!cmp)
			new_set = add(new_set, iter1->data);
	}

	return new_set;
}

// F14
Node *symmetric_difference_set(Node *set1, Node *set2)
{
	auto un = union_set(set1, set2);
	auto inter = intersection_set(set1, set2);
	auto diff = difference_set(un, inter);

	delete_set(inter);
	delete_set(un);

	return diff;
}
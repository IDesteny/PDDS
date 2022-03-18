#pragma once
#include <set>
#include <string>
#include <algorithm>
#include <iterator>

namespace Set_5
{
	class Set
	{
		std::set<int> st;

	public:
		Set() = default;
		Set(int count, int min, int max);
		int size();
		bool own(int val);
		bool isEmpty();
		bool add(int val);
		std::string print(char sp = ' ');
		bool subset(const Set &set) const;
		bool quality(const Set &set);
		Set union_set(const Set &set);
		Set intersection_set(const Set &set);
		Set difference_set(const Set &set);
		Set symmetric_difference_set(const Set &set);
	};
}
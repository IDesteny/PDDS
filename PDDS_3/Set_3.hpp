#pragma once
#include <string>

namespace Set_3
{
	class Set
	{
		struct Node
		{
			Node *next;
			int data;
		};

		Node *head = nullptr;
		int len;

	public:
		Set() = default;
		Set(int count, int min, int max);
		Set(Set &&set) noexcept;
		~Set();
		bool own(int val) const;
		bool add(int val);
		bool isEmpty();
		int size() const;
		std::string print(char sp = ' ');
		bool subset(const Set &set) const;
		bool quality(const Set &set);
		Set union_set(const Set &set);
		Set intersection_set(const Set &set);
		Set difference_set(const Set &set);
		Set symmetric_difference_set(const Set &set);
	};
}
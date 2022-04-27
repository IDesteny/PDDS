#pragma once
#include <algorithm>
#include <string>
#include <set>

class BinarySearchTree
{
	std::set<int> st;
	using _Nodeptr = std::set<int>::const_iterator::_Nodeptr;

	void _BypassTD(const auto t, auto &s) const noexcept;
	void _BypassDT(const auto t, auto &s) const noexcept;

	const _Nodeptr _GetRoot() const noexcept;

public:
	explicit BinarySearchTree();
	explicit BinarySearchTree(const int n, const int mn, const int mx) noexcept;

	bool Add(const int v) noexcept;
	bool IsEmpty() const noexcept;
	void Delete() noexcept;

	std::string BypassDT() const noexcept;
	std::string BypassTD() const noexcept;
	std::string BypassLR() const noexcept;
};
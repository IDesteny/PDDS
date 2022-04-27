#pragma once
#include <algorithm>
#include <string>
#include <set>

class BinarySearchTree
{
	std::set<int> st;
	using _Nodeptr = decltype(st.begin()._Ptr);

	void _BypassTD(const auto t, auto &s) const noexcept;
	void _BypassDT(const auto t, auto &s) const noexcept;

	const _Nodeptr _GetRoot() const noexcept;

public:
	explicit BinarySearchTree();
	explicit BinarySearchTree(const int n, const int mn, const int mx) noexcept;

	bool IsEmpty() const noexcept;
	bool Add(const int v) noexcept;
	void Delete() noexcept;

	std::string BypassDT() const noexcept;
	std::string BypassTD() const noexcept;
	std::string BypassLR() const noexcept;
};
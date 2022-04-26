#pragma once
#include <algorithm>
#include <string>
#include <set>

class BinarySearchTree
{
private:
	std::set<int> st;
	using _Nodeptr = std::allocator<std::_Tree_node<int, void *>>::value_type *;

public:
	explicit BinarySearchTree();
	explicit BinarySearchTree(const int n, const int mn, const int mx) noexcept;
	bool IsEmpty() const noexcept;
	bool Add(const int v) noexcept;
	void Delete() noexcept;
private:
	void _BypassTD(const _Nodeptr t, std::string &s) const noexcept;
	void _BypassDT(const _Nodeptr t, std::string &s) const noexcept;
	const _Nodeptr _GetRoot() const noexcept;

public:
	std::string BypassDT() const noexcept;
	std::string BypassTD() const noexcept;
	std::string BypassLR() const noexcept;
};
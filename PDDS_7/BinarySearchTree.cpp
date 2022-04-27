#include "BinarySearchTree.hpp"

BinarySearchTree::BinarySearchTree() = default;

BinarySearchTree::BinarySearchTree(const int n, const int mn, const int mx) noexcept
{
	for (auto i = 0; i < n; ++i)
		while (!Add(mn + mn + rand() % (mx - mn)));
}

bool BinarySearchTree::IsEmpty() const noexcept
{
	return st.empty();
}

bool BinarySearchTree::Add(const int v) noexcept
{
	return st.emplace(v).second;
}

void BinarySearchTree::Delete() noexcept
{
	st.clear();
}

void BinarySearchTree::_BypassTD(const auto t, auto &s) const noexcept
{
	if (!t->_Isnil)
	{
		s += std::to_string(t->_Myval);
		_BypassTD(t->_Left, s);
		_BypassTD(t->_Right, s);
	}
}

void BinarySearchTree::_BypassDT(const auto t, auto &s) const noexcept
{
	if (!t->_Isnil)
	{
		_BypassDT(t->_Left, s);
		_BypassDT(t->_Right, s);
		s += std::to_string(t->_Myval);
	}
}

auto BinarySearchTree::_GetRoot() const noexcept -> const _Nodeptr
{
	auto t = st.begin()._Ptr, t2 = t;
	
	do t = t2;
	while (!(t2 = t2->_Parent)->_Isnil);

	return t;
}

std::string BinarySearchTree::BypassDT() const noexcept
{
	std::string s;
	_BypassDT(_GetRoot(), s);
	return s;
}

std::string BinarySearchTree::BypassTD() const noexcept
{
	std::string s;
	_BypassTD(_GetRoot(), s);
	return s;
}

std::string BinarySearchTree::BypassLR() const noexcept
{
	std::string s;
	std::for_each(st.begin(), st.end(), [&](const auto v) { s += std::to_string(v); });
	return s;
}
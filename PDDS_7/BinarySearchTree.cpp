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

void BinarySearchTree::_BypassTD(const _Nodeptr t, std::string &s) const noexcept
{
	if (!t->_Isnil)
	{
		s.append(std::to_string(t->_Myval));
		_BypassTD(t->_Left, s);
		_BypassTD(t->_Right, s);
	}
}

void BinarySearchTree::_BypassDT(const _Nodeptr t, std::string &s) const noexcept
{
	if (!t->_Isnil)
	{
		_BypassDT(t->_Left, s);
		_BypassDT(t->_Right, s);
		s.append(std::to_string(t->_Myval));
	}
}

const BinarySearchTree::_Nodeptr BinarySearchTree::_GetRoot() const noexcept
{
	_Nodeptr t = st.begin()._Ptr;
	_Nodeptr t2 = t;

	for (;;)
	{
		t = t2;
		t2 = t2->_Parent;
		if (t2->_Isnil)
			break;
	}
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
	std::for_each(st.begin(), st.end(), [&s](const int &v) { s.append(std::to_string(v)); });
	return s;
}
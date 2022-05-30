#include "String.hpp"

String::String() = default;

String::String(const int n, const int mn, const int mx) noexcept
{
	for (auto &&i : std::ranges::views::iota(0, n))
		while (!_add(mn + mn + rand() % (mx - mn)));
}

bool String::_add(auto &&v) noexcept
{
	return own(v) || reinterpret_cast<bool *>(&(s += v));
}

bool String::own(const int v) const noexcept
{
	return s.find(v) != std::string::npos;
}

int String::size() const noexcept
{
	return s.size();
}

bool String::subset(const String &_s) const noexcept
{
	return _s.s.find(s);
}

bool String::quality(const String &_s) const noexcept
{
	return _s.subset(*this) && subset(_s);
}

String String::union_set(const String &_s) const noexcept
{
	auto ns(_s);
	std::ranges::for_each(_s.s, [&](auto &&v) { ns._add(v); });
	return ns;
}

String String::intersection_set(const String &_s) const noexcept
{
	String ns;
	std::ranges::for_each(_s.s, [&](auto &&v) { ns._add(v); });
	return ns;
}

String String::difference_set(const String &_s) const noexcept
{
	auto ns(_s);
	std::ranges::for_each(_s.s, [&](auto &&v) { !own(v) && ns._add(v); });
	return ns;
}

String String::symmetric_difference_set(const String &_s) const noexcept
{
	return intersection_set(_s).difference_set(union_set(_s));
}
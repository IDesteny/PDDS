#include "String.hpp"

String::String() = default;

String::String(const int n, const int mn, const int mx) noexcept
{
	for (auto i = 0; i < n; ++i)
		while (!_add(mn + mn + rand() % (mx - mn)));
}

bool String::_add(const auto v) noexcept
{
	return !own(v) ? reinterpret_cast<bool *>(&(s += v)) : false;
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
	String new_string(_s);
	std::for_each(_s.s.begin(), _s.s.end(), [&](const auto v) { new_string._add(v); });
	return new_string;
}

String String::intersection_set(const String &_s) const noexcept
{
	String new_string;
	std::for_each(_s.s.begin(), _s.s.end(), [&](const auto v) { new_string._add(v); });
	return new_string;
}

String String::difference_set(const String &_s) const noexcept
{
	String new_string;
	std::for_each(_s.s.begin(), _s.s.end(), [&](const auto v) { if (!own(v)) new_string._add(v); });
	return new_string;
}

String String::symmetric_difference_set(const String &_s) const noexcept
{
	return intersection_set(_s).difference_set(union_set(_s));
}
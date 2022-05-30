#pragma once
#include <string>
#include <ranges>
#include <algorithm>

class String
{
	std::basic_string<int> s;

public:
	explicit String();
	explicit String(const int n, const int min, const int max) noexcept;
	bool own(const int v) const noexcept;
	int size() const noexcept;
	bool subset(const String &_s) const noexcept;
	bool quality(const String &_s) const noexcept;
	String union_set(const String &_s) const noexcept;
	String intersection_set(const String &_s) const noexcept;
	String difference_set(const String &_s) const noexcept;
	String symmetric_difference_set(const String &_s) const noexcept;

private:
	bool _add(auto &&v) noexcept;
};
#pragma once
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>

class String
{
	std::string s;

public:
	String() = default;

	String(std::string s) : s(s) {}

	String(int n, int min, int max)
	{
		s.reserve(n);

		for (auto i = 0; i < n; ++i)
		{
			char ch;
			while (own(ch = min + min + rand() % (max - min)));
			s += ch;
		}
	}

	bool own(char ch)
	{
		return s.find(ch) != std::string::npos;
	}

	int size()
	{
		return s.size();
	}

	bool subset(const String &_s)
	{
		return _s.s.find(s);
	}

	bool quality(const String &_s)
	{
		return std::equal(s.begin(), s.end(), _s.s.begin());
	}

	String union_set(const String &_s)
	{
		String new_string(s);

		for (auto &&iter : _s.s)
			if (own(iter))
				new_string.s += iter;

		return new_string;
	}

	String intersection_set(const String &_s)
	{
		String new_string;

		for (auto &&iter : _s.s)
			if (own(iter))
				new_string.s += iter;

		return new_string;
	}

	String difference_set(const String &_s)
	{
		String new_string;

		for (auto &&iter : _s.s)
			if (!own(iter))
				new_string.s += iter;

		return new_string;
	}

	String symmetric_difference_set(const String &_s)
	{
		return intersection_set(_s).difference_set(union_set(_s));
	}
};
#include "String.hpp"

String::String() = default;

String::String(std::string s) : s(s) {}

String::String(int n, int min, int max)
{
	s.reserve(n);

	for (auto i = 0; i < n; ++i)
	{
		char ch;
		while (own(ch = min + min + rand() % (max - min)));
		s += ch;
	}
}

bool String::own(char ch)
{
	return s.find(ch) != std::string::npos;
}

int String::size()
{
	return s.size();
}

bool String::subset(const String & _s) const
{
	return _s.s.find(s);
}

bool String::quality(const String & _s)
{
	return _s.subset(*this) && subset(_s);
}

String String::union_set(const String & _s)
{
	String new_string(s);

	for (auto &&iter : _s.s)
		if (own(iter))
			new_string.s += iter;

	return new_string;
}

String String::intersection_set(const String & _s)
{
	String new_string;

	for (auto &&iter : _s.s)
		if (own(iter))
			new_string.s += iter;

	return new_string;
}

String String::difference_set(const String & _s)
{
	String new_string;

	for (auto &&iter : _s.s)
		if (!own(iter))
			new_string.s += iter;

	return new_string;
}

String String::symmetric_difference_set(const String & _s)
{
	return intersection_set(_s).difference_set(union_set(_s));
}
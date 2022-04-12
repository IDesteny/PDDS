#pragma once
#include <string>

class String
{
	std::string s;

public:
	String();
	String(std::string s);
	String(int n, int min, int max);
	bool own(char ch);
	int size();
	bool subset(const String &_s) const;
	bool quality(const String &_s);
	String union_set(const String &_s);
	String intersection_set(const String &_s);
	String difference_set(const String &_s);
	String symmetric_difference_set(const String &_s);
};
#include "../PDDS_2/Set_2.hpp"
#include "../PDDS_3/Set_3.hpp"
#include "../PDDS_4/Set_4.hpp"
#include "../PDDS_5/Set_5.hpp"
#include "../PDDS_6/Benchmark.hpp"
#include "String.hpp"
#include <iostream>
#include <vector>
#include <windows.h>

#pragma warning(disable: 26444)

auto SetPos(short x, short y)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x, y });
}

auto GetConsoleCursorPosition()
{
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cbsi);
	return cbsi.dwCursorPosition;
}

auto BenchmarkSet2(int n, int mn, int mx)
{
	std::vector<int64_t> t(10);

	auto s1 = create(n, mn, mx);
	auto s2 = create(n, mn, mx);

	BENCHMARK(t[0], create(n, mn, mx));
	BENCHMARK(t[1], size(s1));
	BENCHMARK(t[2], subset(s1, s1));
	BENCHMARK(t[3], subset(s2, s1));
	BENCHMARK(t[4], quality(s1, s1));
	BENCHMARK(t[5], quality(s2, s1));
	BENCHMARK(t[6], union_set(s1, s2));
	BENCHMARK(t[7], intersection_set(s1, s2));
	BENCHMARK(t[8], difference_set(s1, s2));
	BENCHMARK(t[9], symmetric_difference_set(s1, s2));

	return t;
}

auto BenchmarkSet3(int n, int mn, int mx)
{
	std::vector<int64_t> t(10);

	Set_3::Set s1(n, mn, mx);
	Set_3::Set s2(n, mn, mx);

	BENCHMARK(t[0], Set_3::Set(n, mn, mx));
	BENCHMARK(t[1], s1.size());
	BENCHMARK(t[2], s1.subset(s1));
	BENCHMARK(t[3], s2.subset(s1));
	BENCHMARK(t[4], s1.quality(s1));
	BENCHMARK(t[5], s2.quality(s1));
	BENCHMARK(t[6], s1.union_set(s2));
	BENCHMARK(t[7], s1.intersection_set(s2));
	BENCHMARK(t[8], s1.difference_set(s2));
	BENCHMARK(t[9], s1.symmetric_difference_set(s2));

	return t;
}

auto BenchmarkSet4(int n, int mn, int mx)
{
	std::vector<int64_t> t(10);

	Set_4::Set s1(n, mn, mx);
	Set_4::Set s2(n, mn, mx);

	BENCHMARK(t[0], Set_4::Set(n, mn, mx));
	BENCHMARK(t[1], s1.size());
	BENCHMARK(t[2], s1.subset(s1));
	BENCHMARK(t[3], s2.subset(s1));
	BENCHMARK(t[4], s1.quality(s1));
	BENCHMARK(t[5], s2.quality(s1));
	BENCHMARK(t[6], s1.union_set(s2));
	BENCHMARK(t[7], s1.intersection_set(s2));
	BENCHMARK(t[8], s1.difference_set(s2));
	BENCHMARK(t[9], s1.symmetric_difference_set(s2));

	return t;
}

auto BenchmarkSet5(int n, int mn, int mx)
{
	std::vector<int64_t> t(10);

	Set_5::Set s1(n, mn, mx);
	Set_5::Set s2(n, mn, mx);

	BENCHMARK(t[0], Set_5::Set(n, mn, mx));
	BENCHMARK(t[1], s1.size());
	BENCHMARK(t[2], s1.subset(s1));
	BENCHMARK(t[3], s2.subset(s1));
	BENCHMARK(t[4], s1.quality(s1));
	BENCHMARK(t[5], s2.quality(s1));
	BENCHMARK(t[6], s1.union_set(s2));
	BENCHMARK(t[7], s1.intersection_set(s2));
	BENCHMARK(t[8], s1.difference_set(s2));
	BENCHMARK(t[9], s1.symmetric_difference_set(s2));

	return t;
}

auto BenchmarkString(int n, int mn, int mx)
{
	std::vector<int64_t> t(10);

	String s1(n, mn, mx);
	String s2(n, mn, mx);

	BENCHMARK(t[0], String(n, mn, mx));
	BENCHMARK(t[1], s1.size());
	BENCHMARK(t[2], s1.subset(s1));
	BENCHMARK(t[3], s2.subset(s1));
	BENCHMARK(t[4], s1.quality(s1));
	BENCHMARK(t[5], s2.quality(s1));
	BENCHMARK(t[6], s1.union_set(s2));
	BENCHMARK(t[7], s1.intersection_set(s2));
	BENCHMARK(t[8], s1.difference_set(s2));
	BENCHMARK(t[9], s1.symmetric_difference_set(s2));

	return t;
}

int main()
{
	using namespace std;

	constexpr auto n = 10;

	vector<vector<int64_t>> ts = {
		BenchmarkSet2(n, 0, n),
		BenchmarkSet3(n, 0, n),
		BenchmarkSet4(n, 0, n),
		BenchmarkSet5(n, 0, n),
		BenchmarkString(n, 0, n)
	};

	vector<string> names {
		"create",
		"size",
		"subset",
		"subset",
		"quality",
		"quality",
		"union",
		"inter",
		"diff",
		"symdiff"
	};

	vector<string> libnames = {
		"list(func)",
		"list(class)",
		"list(std)",
		"set(std)",
		"string(std)"
	};

	cout << "+----------+------------+-------------+-----------+----------+-------------+-------------+-------------+" << endl;
	cout << "|   name   | list(func) | list(class) | list(std) | set(std) | string(std) |   fastest   |   slowest   |" << endl;
	cout << "+----------+------------+-------------+-----------+----------+-------------+-------------+-------------+" << endl;

	auto pos = GetConsoleCursorPosition();

	for (auto i = 0; i < 10; ++i)
	{
		auto fastest = {
			ts[0][i],
			ts[1][i],
			ts[2][i],
			ts[3][i],
			ts[4][i]
		};

		auto max = max_element(fastest.begin(), fastest.end()) - fastest.begin();
		auto min = min_element(fastest.begin(), fastest.end()) - fastest.begin();

		cout << "| " << names[i];
		SetPos(11, pos.Y + i);
		cout << "| " << ts[0][i];
		SetPos(24, pos.Y + i);
		cout << "| " << ts[1][i];
		SetPos(38, pos.Y + i);
		cout << "| " << ts[2][i];
		SetPos(50, pos.Y + i);
		cout << "| " << ts[3][i];
		SetPos(61, pos.Y + i);
		cout << "| " << ts[4][i];
		SetPos(75, pos.Y + i);
		cout << "| " << libnames[min];
		SetPos(89, pos.Y + i);
		cout << "| " << libnames[max];
		SetPos(103, pos.Y + i);
		cout << "|\n";
	}

	cout << "+----------+------------+-------------+-----------+----------+-------------+-------------+-------------+" << endl;
}
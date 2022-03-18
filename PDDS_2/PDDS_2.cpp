#include <iostream>
#include "Set_2.hpp"

using namespace std;

int main()
{
	srand(time(nullptr));

	auto set1 = create(6 + rand() % (9 - 6), 10, 60);
	auto set2 = create(6 + rand() % (9 - 6), 10, 60);

	auto r1 = subset(set1, set2);
	auto r2 = quality(set1, set2);
	auto r3 = subset(set1, set1);
	auto r4 = quality(set1, set1);

	auto set3 = union_set(set1, set2);
	auto set4 = intersection_set(set1, set2);
	auto set5 = difference_set(set1, set2);
	auto set7 = difference_set(set2, set1);
	auto set6 = symmetric_difference_set(set1, set2);

	cout
		<< "set1:\t" << print(set1, ' ') << '\n'
		<< "set2:\t" << print(set2, ' ') << '\n'
		<< "F9:\t" << r1 << '\n'
		<< "F10:\t" << r2 << '\n'
		<< "F9:\t" << r3 << '\n'
		<< "F10:\t" << r4 << '\n'
		<< "F11:\t" << print(set3, ' ') << '\n'
		<< "F12:\t" << print(set4, ' ') << '\n'
		<< "F13:\t" << print(set5, ' ') << '\n'
		<< "F14:\t" << print(set6, ' ') << '\n'
		<< "F13:\t" << print(set7, ' ') << '\n';
		
}
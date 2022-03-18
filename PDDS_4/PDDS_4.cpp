#include <iostream>
#include "Set_4.hpp"
using namespace std;
using namespace Set_4;

int main()
{
	srand(time(nullptr));

	Set set1(16, 10, 60);
	Set set2(16, 10, 60);

	auto set3 = set1.union_set(set2);
	auto set4 = set1.intersection_set(set2);
	auto set5 = set1.symmetric_difference_set(set2);
	auto set6 = set1.difference_set(set2);

	cout << set1.print() << endl;
	cout << set2.print() << endl;
	cout << set3.print() << endl;
	cout << set4.print() << endl;
	cout << set5.print() << endl;
	cout << set6.print() << endl;
}
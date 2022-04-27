#include "BinarySearchTree.hpp"
#include <iostream>

int main()
{
	using namespace std;

	BinarySearchTree bst1;
	BinarySearchTree bst2(5, 0, 5);

	cout << bst2.Add(9) << '\n';
	cout << bst2.IsEmpty() << '\n';
	cout << bst2.BypassDT() << '\n';
	cout << bst2.BypassTD() << '\n';
	cout << bst2.BypassLR() << '\n';
}
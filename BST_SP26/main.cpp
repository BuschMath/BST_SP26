#include <iostream>
#include "BST.h"

int main()
{
	BST<int> tree;

	tree.insertItem(50);
	tree.insertItem(25);
	tree.insertItem(75);
	tree.insertItem(12);
	tree.insertItem(37);
	tree.insertItem(63);
	tree.insertItem(100);
	tree.insertItem(5);
	tree.insertItem(20);
	tree.insertItem(30);
	tree.insertItem(70);
	tree.insertItem(110);

	tree.print();

	cout << "Did we find 30: " << tree.searchItem(30) << "\n";
	cout << "Did we find 42: " << tree.searchItem(42) << "\n";

	tree.deleteItem(25);
	tree.deleteItem(75);

	tree.print();

	return 0;
}
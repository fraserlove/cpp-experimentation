#include <iostream>

#include "list.h"

int main() {

	// Test Code
	int array[] = { 0, 1, 2, 3, 4, 5 };

	List list(array, 6);
	list.PrintList();
	list.AddNode(10,8);
	list.PrintList();
	list.AddNode(10,6);
	list.PrintList();
	list.AddNode(10,5);
	list.PrintList();
	list.AddNode(10,0);
	list.PrintList();
}
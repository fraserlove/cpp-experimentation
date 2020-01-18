#include <iostream>

#include "list.h"

int main() {

	// Test Code
	List list;
	list.AddNode(0);
	list.AddNode(1);
	list.AddNode(2);
	list.AddNode(3);
	list.AddNode(4);
	std::cout << list.FindLength() << std::endl;
	list.InsertNode(10, 0);
	list.PrintList();
	std::cout << list.FindLength() << std::endl;
	list.InsertNode(13, 3);
	list.AddNode(5);
	std::cout << list.FindLength() << std::endl;
	list.PrintList();
	list.DeleteNode(5);
	list.DeleteNode(10);
	list.DeleteNode(13);
	std::cout << list.FindLength() << std::endl;
	list.PrintList();

}
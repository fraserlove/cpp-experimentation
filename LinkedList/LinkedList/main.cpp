#include <iostream>

#include "list.h"

void convToArray(List list) {

	int* array = list.ConvertToArray();
	for (int i = 0; i < list.FindLength(); i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
	delete[] array;
}

List addNodes(List list, int n) {
	for (int i = 0; i < n; i++) {
		list.AddNode(i);
	}
	return list;
}

void testCode() {

	List list;
	int n = 6;
	list = addNodes(list, n);
	list.PrintStructure();
	list.Reverse();
	list.AddNode(-1);
	list.AddNode(6, 0);
	list.PrintStructure();
	convToArray(list);
}

int main() {

	testCode();
}
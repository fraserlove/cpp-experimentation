#include <iostream>

#include "list.h"

void convToArray(List list, int n) {

	int* array = list.ConvertToArray();
	for (int i = 0; i < n; i++) {
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
	list.PrintStructure();
	convToArray(list, n);
}

int main() {

	testCode();
}
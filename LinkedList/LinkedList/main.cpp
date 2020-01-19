#include <iostream>

#include "list.h"

void testCode() {

	List list;
	int n = 10;
	for (int i = 0; i < n; i++) {
		list.AddNode(i);
	}
	list.PrintList();

	int* array = list.ConvertToArray();
	for (int i = 0; i < n; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
	delete[] array;
}

int main() {

	testCode();
}
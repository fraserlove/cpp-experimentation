#include <iostream>

int main() {

	int a = 1;
	int b = 2;
	int c = 3;
	int intArray[4] = { 1,2,3,4 };
	char first[] = "Fraser";
	first[0] = 'X';
	const char* last = "Love";
	// last[0] = 'B'; Doesnt work as char* is const

	std::cout << "Address of A: " << &a << std::endl;
	std::cout << "Address of B: " << &b << std::endl;
	std::cout << "Address of C: " << &c << std::endl;

	std::cout << "\nAddress of Array: " << &intArray << std::endl;
	std::cout << "Array Address Range: " << &intArray << " - " << &intArray + *intArray << std::endl;
	std::cout << "Array Details: Type - int[]" << " Size of Type - " << sizeof(*intArray) << " Total Size of Array - " << sizeof(intArray) << std::endl;

}
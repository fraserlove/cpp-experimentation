#include <iostream>

void swapValues(int* p1, int* p2) { // Pass by pointer
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int main() {
	int var1 = 10;
	int var2 = 20;
	swapValues(&var1, &var2);
	std::cout << var1 << std::endl;
	std::cout << var2 << std::endl;
}

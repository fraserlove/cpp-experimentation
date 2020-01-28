#include <iostream>

#include "Stack.h"

int main() {
	int vals[6] = { 0,1,2,3,4,5 };
	Stack<int> stack(vals, 6);
	stack.Show();
	stack.Pop();
	stack.Push(6);
	std::cout << stack.Peek() << std::endl;
	stack.Show();
}
#include <iostream>

#include "array.h"

int main() {
	int vals[6] = { 0,1,2,3,4,5 };
	Array<int> array;
	array.Push(vals, 6);
	array.Show();

}
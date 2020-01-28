#include <iostream>

#include "DynamicArray.h"

int main() {
	int vals[6] = { 0,1,2,3,4,5 };
	DynamicArray<int> Array(vals, 6);
	Array.ShowDebug();
	Array.Reverse();
	Array.Show();

}

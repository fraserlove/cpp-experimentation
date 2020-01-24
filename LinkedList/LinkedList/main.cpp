#include <iostream>

#include "list.h"

int main() {
	int vals[6] = { 0,1,2,3,4,5 };
	List<int> list(vals, 6);
	list.ShowDebug();
	list.Reverse();
	list.Show();
}
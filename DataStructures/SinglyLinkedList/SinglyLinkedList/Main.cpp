#include <iostream>

#include "SinglyLinkedList.h"

int main() {
	int vals[6] = { 0,1,2,3,4,5 };
	SinglyLinkedList<int> List(vals, 6);
	List.ShowDebug();
	List.Reverse();
	List.Show();
}

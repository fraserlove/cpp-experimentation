#include <iostream>

#include "PriorityQueue.h"

int main() {
	int vals[6] = { 1,2,3,4,5,6 };
	PQueue<int> pqueue(vals, 6, 0);
	pqueue.ShowDebug();
	std::cout << pqueue.Dequeue() << std::endl;
	std::cout << pqueue.ValidHeap() << std::endl;
}
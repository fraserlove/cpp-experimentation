#include <iostream>

#include "PriorityQueue.h"

int main() {
	int vals[6] = { 0,1,2,3,4,5 };
	PQueue<int> pqueue(vals, 6);
	pqueue.ShowDebug();
}
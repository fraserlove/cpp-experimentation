#include <iostream>

#include "Queue.h"

int main() {
	int vals[6] = { 0,1,2,3,4,5 };
	Queue<int> queue(vals, 6);
	queue.Show();
	queue.Dequeue();
	queue.Enqueue(6);
	std::cout << queue.Peek() << std::endl;
	queue.Show();
}
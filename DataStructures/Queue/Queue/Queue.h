/*
Queue Implementation With Singly Linked List
Developed by Fraser Love
Created 28/01/20
Latest Release 28/01/20

Uses C++ Templates and can be used with integers, floats and characters
Singly linked list implementation from data-structures library
Linked list insertion at tail and deletion at head allow for constant time Enqueue() and Dequeue() operations
*/

#pragma once

#include "SinglyLinkedList.h"

template <class T>
class Queue {
private:
	SinglyLinkedList<T> list;

public:
	Queue();
	Queue(T data);
	Queue(T data[], int size);
	~Queue();

	void Enqueue(T data); // Add an object to the back of the queue
	void Clear(); // Removes all objects from the queue
	void Show(); // Displays all objects in the queue

	int Length(); // Return the number of objects in the queue

	bool IsEmpty(); // Check if the queue is empty

	T Dequeue(); // Remove an object from the front of the queue
	T Peek(); // Returns the object at the front of the queue without removing it
};

template class Queue<int>;
template class Queue<float>;
template class Queue<char>;
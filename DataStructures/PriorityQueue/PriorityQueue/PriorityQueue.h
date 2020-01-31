/*
Min Priority Queue Implementation Using Binary Heaps
Developed by Fraser Love
Created 29/01/20
Latest Release 29/01/20

Uses C++ Templates and can be used with integers, floats, characters and strings
Dynamic array implementation from data-structures library
Binary heap implemented using a dynamic array
Default priority queue is a minimum priority queue
Future implementation could include a HashTable for O(log(n)) removeals and O(1) element containment check
*/

#pragma once

#include "DynamicArray.h"

template <class T>
class PQueue {
private:
	DynamicArray<T>* heap;

	bool is_min_heap; // Operator used to change between min or max heaps. 0 = min and 1 = max

	void HeapifyUp(int idx); // Restablishes the heap property, moving upwards, O(log(n))
	void HeapifyDown(int idx); // Restablishes the heap property, moving downwards, O(log(n))
	void Swap(int idx_1, int idx_2); // Swaps two nodes using their indices, O(1)

	int Parent(int idx);  // Returns the index of a parent at a specific index
	int LeftChild(int idx); // Returns the index of the left child at a specific index
	int RightChild(int idx); // Returns the index of the left child at a specific index

	bool Less(int idx_1, int idx_2); // Used for min heaps, checks if the node held at index 1 is less than the node held at index 2, O(1)
	bool Comparison(int idx_1, int idx_2); // Executes either the Less() or More() function depending if min or max heap

	T Remove(int idx); // Removes a node at a specific index in the heap, O(n)

public:
	PQueue(bool min_heap = 1);
	PQueue(int size, bool min_heap = 1);
	PQueue(T data[], int size, bool min_heap = 1);
	~PQueue();

	void Enqueue(T data); // Adds data to the priority queue and maintains the heap property
	void Clear(); // Overwrites all data in the priority queue and deallocates the heap from memory
	void ShowDebug(); // Shows the dynamic array used to represent the heap

	int Length(); // Returns the length of the priority queue

	bool IsEmpty(); // Checks if the priority queue is empty
	bool RemoveValue(T data); // Removes a specific value from the priority queue, O(n)
	bool Contains(T data); // Checks if the priority queue contains a specific element
	bool IsMin(); // Checks if the priority queue is a minimum heap
	bool IsMax(); // Checks if the priority queue is a maximum heap
	bool ValidHeap(int idx = 0); // For debug, checks to make sure there are no errors in the heap and that the heap propery is still held

	T Dequeue(); // Removes and returns the lowest priority element in the priority queue
	T Peek(); // Returns the value of the element with the lowest priority in the priority queue 
};
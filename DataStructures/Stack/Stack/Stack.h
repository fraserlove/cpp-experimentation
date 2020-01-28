/*
Stack Implementation With Singly Linked List
Developed by Fraser Love
Created 27/01/20
Latest Release 27/01/20

Uses C++ Templates and can be used with integers, floats and characters
Singly linked list implementation from data-structures library
Linked list insertion and deletion at head is used for constant time Pop() and Push() operatons
*/

#pragma once

#include "SinglyLinkedList.h"

template <class T>
class Stack {
private:
	SinglyLinkedList<T> list;

public:
	Stack();
	Stack(T data);
	Stack(T data[], int size);
	~Stack();

	void Push(T data); // Push an object on the stack
	void Clear(); // Removes all objects from the stack
	void Show(); // Displays all objects in the stack

	int Length(); // Return the number of objects in the stack

	bool IsEmpty(); // Check if the stack is empty

	T Pop(); // Pops an object off the stack
	T Peek(); // Returns the object at the top of the stack without removing it
};

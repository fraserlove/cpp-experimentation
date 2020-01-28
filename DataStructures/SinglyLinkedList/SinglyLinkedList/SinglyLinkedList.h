/*
Singly Linked List Implementation
Developed by Fraser Love
Created 17/01/20
Latest Release 26/01/20

Uses C++ Templates and can be used with integers, floats and characters
*/

#pragma once

template <class T>
class SinglyLinkedList {
private:
	struct Node {
		T data;
		Node* next;
	};

	Node* head;
	Node* curr;
	Node* temp;

	int len;

public:
	SinglyLinkedList();
	SinglyLinkedList(T data[], int size);
	~SinglyLinkedList();

	void Set(int idx, T data); // Sets the data the node at a specific position with the new data supplied
	void Add(T data); // Adds a new node to the end of the linked list with the data specified
	void Add(int idx, T data); // Adds a new node to the linked list at a specific location with the data specified
	void Clear(); // Overwrites all data and pointers in the linked list and deallocates nodes from the heap
	void Reverse(); // Reverses the linked list by updating pointers to the previous node
	void Show(); // Displays the entire linked list
	void ShowAsString(); // Displays the entire linked list without any formatting
	void ShowDebug(); // Displays the entire linked list, showing its structure and pointers for debugging

	int Length(); // Returns the length of the linked list
	int Find(T data); // Returns the position of the first instance of a specific object in the linked list
	int* ToArray(); // Converts the linked list to an array and returns a pointer to the first element

	bool IsEmpty(); // Checks if the linked list is empty
	bool RemoveValue(T data); // Removes the first instance of a node with a specific object in the linked list
	bool Contains(T data); //  Checks if an object is present in the dynamic array

	T Access(int idx); // Returns the object held in a specific node
	T Peek(); // Returns the value of the first node in the array
	T Remove(int idx); // Removes a node by its position in the linked list and returns its value
}; 
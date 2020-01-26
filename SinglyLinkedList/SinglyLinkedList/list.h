/*
Linked List Implementation
Developed by Fraser Love
Created 17/01/20
Latest Release 24/01/20

Uses C++ Templates and can be used with integers, floats and characters
*/

#pragma once

template <class T>
class List {
private:
	struct node {
		T data;
		node* next;
	};

	node* head;
	node* curr;
	node* temp;

	void initPtrs(); // Initialises pointers to null

public:
	List();
	List(T initArray[], int size);
	~List();

	void AddNode(T data); // Adds a new node to the end of the linked list with the data specified
	void AddNode(int idx, T data); // Ades a new node to the linked list at a specific location with the data specified
	void RemoveValue(T data); // Deletes the first instance of a node with a specified value in the linked list
	void DeleteNode(int idx); // Deletes a node by its index in the linked list
	void Update(int idx, T data); // Updates the data in a specific node with the new data supplied
	void Reverse(); // Reverses the linked list by updating pointers to the previous node
	void Show(); // Displays the entire linked list
	void ShowDebug(); // Displays the entire linked list, showing its structure and pointers for debugging

	int Length(); // Returns the length of the linked list
	int Access(int idx); // Returns the data held in a specific node
	int* ToArray(); // Converts the linked list to an array and returns a pointer to the first element
}; 
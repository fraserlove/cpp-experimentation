#pragma once

class List {
private:

	struct node {
		int data;
		node* next;
	};

	node* head;
	node* curr;
	node* temp;

public:

	List();
	void AddNode(int addData);
	void DeleteNode(int delData);
	void PrintList();

	// TODO - Create InsertNode (int instData, node* instIndex) 
	// Add index attribute
	// Overload del function to delete by passing in an index
	// Create sorting and search (return index) functions
	// Create destructor method removing all nodes
}; 
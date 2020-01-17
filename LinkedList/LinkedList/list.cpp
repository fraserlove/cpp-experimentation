#include <iostream>

#include "list.h"

List::List() {
	head = NULL;
	curr = NULL;
	temp = NULL;
}

void List::AddNode(int addData) {
	node* newNode = new node;
	newNode->next = NULL;
	newNode->data = addData;

	if (head != NULL) {
		curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = newNode;
	}
	else {
		head = newNode;
	}
	std::cout << "Info: Added instance of " << addData << std::endl;
}

void List::DeleteNode(int delData) {
	node* delPtr = NULL;
	temp = head;
	curr = head;
	
	while (curr != NULL && curr->data != delData) {
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL) {
		delete delPtr;
		std::cout << "Deletion Error: No instance of " << delData << " found" << std::endl;
	}
	else {
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;
		if (delPtr == head) {
			head = head->next;
			temp = NULL;
		}
		delete delPtr;
		std::cout << "Info: Removed instance of " << delData << std::endl;
	}
}

void List::PrintList() {
	curr = head;
	std::cout << "List Elements: ";
	while (curr != NULL) {
		if (curr == head) {
			std::cout << curr->data;
		}
		else {
			std::cout << ", " << curr->data;
		}
		curr = curr->next;
	}
	std::cout << std::endl;
}
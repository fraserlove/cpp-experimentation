#include <iostream>

#include "list.h"

List::List() {
	//std::cout << "Info: Creating List" << std::endl;
	head = NULL;
	curr = NULL;
	temp = NULL;
}

List::~List () {
	//std::cout << "Info: Deleting List" << std::endl;
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
	//std::cout << "Info: Added instance of " << addData << std::endl;
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
		std::cout << "Error: No instance of " << delData << " found for deletion" << std::endl;
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
		//std::cout << "Info: Removed instance of " << delData << std::endl;
	}
}

void List::InsertNode(int instData, int idx) {
	int length = FindLength();
	idx--;

	if (idx == length - 1) {
		AddNode(instData);
	}
	else if (idx == -1) {
		node* newNode = new node;
		newNode->next = head;
		newNode->data = instData;
		head = newNode;
		//std::cout << "Info: Added instance of " << instData << std::endl;
	}
	else if (idx >= length) {
		std::cout << "Error: Index " << idx << " specified is greater than list bounds" << std::endl;
	}
	else {
		node* newNode = new node;
		newNode->next = NULL;
		newNode->data = instData;

		temp = head;
		curr = head;

		int cIdx = 0;
		bool found = false;

		while (cIdx < length - 1 and !found) {
			if (cIdx == idx) {
				found = true;
			}
			temp = curr;
			curr = curr->next;
			cIdx++;
		}
		temp->next = newNode;
		newNode->next = curr;
		//std::cout << "Info: Added instance of " << addData << std::endl;
	}
}

int List::FindLength() {
	curr = head;
	int idx = 0;

	while (curr != NULL) {
		idx++;
		curr = curr->next;
	}
	return idx;
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
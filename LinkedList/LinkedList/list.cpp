#include <iostream>

#include "list.h"

List::List() {
	initPtrs();
}

List::List(int initArray[], int size) {
	initPtrs();
	for (int i = 0; i < size; i++) {
		AddNode(initArray[i]);
	}
}

List::~List () {
	//std::cout << "Info: Deleting List" << std::endl;
}

void List::initPtrs() {
	//std::cout << "Info: Creating List" << std::endl;
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
	//std::cout << "Info: Added instance of " << addData << std::endl;
}

void List::AddNode(int addData, int idx) {
	int length = FindLength();

	if (idx == length) {
		AddNode(addData);
	}
	else if (idx > length or idx < 0) {
		std::cout << "ADDITION ERROR: Index " << idx << " is outwith list bounds" << std::endl;
	}
	else {
		node* newNode = new node;
		newNode->data = addData;

		if (idx == 0) {
			newNode->next = head;
			head = newNode;
		}
		else {
			temp = head;
			curr = head;

			int cIdx = 0;
			while (cIdx < length and cIdx != idx) {
				temp = curr;
				curr = curr->next;
				cIdx++;
			}
			temp->next = newNode;
			newNode->next = curr;
		}
		//std::cout << "Info: Added instance of " << addData << std::endl;
	}
}

void List::DeleteNodeByInstance(int delData) {
	node* delPtr = NULL;
	temp = head;
	curr = head;
	
	while (curr != NULL && curr->data != delData) {
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL) {
		std::cout << "DELETION ERROR: No instance of " << delData << " found" << std::endl;
	}
	else {
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;

		if (delPtr == head) {
			head = head->next;
			temp = NULL;
		}
		//std::cout << "Info: Removed instance of " << delData << std::endl;
	}
	delete delPtr;
}

void List::DeleteNodeByIndex(int idx) {
	int length = FindLength();

	node* delPtr = NULL;
	temp = head;
	curr = head;

	if (idx >= length or idx < 0) {
		std::cout << "DELETION ERROR: Index " << idx << " is outwith list bounds" << std::endl;
	}
	else {
		int cIdx = 0;
		while (cIdx < length and cIdx != idx) {
			temp = curr;
			curr = curr->next;
			cIdx++;
		}
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;

		if (delPtr == head) {
			head = head->next;
			temp = NULL;
		}
	}
	//std::cout << "INFO: Removed node at index " << idx << std::endl;
	delete delPtr;

}

void List::PrintList() {
	curr = head;

	std::cout << "List : ";
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

int List::FindLength() {
	curr = head;
	int idx = 0;

	while (curr != NULL) {
		idx++;
		curr = curr->next;
	}
	return idx;
}
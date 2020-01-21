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
	//std::cout << "INFO: Deleting List" << std::endl;
}

void List::initPtrs() {
	//std::cout << "INFO: Creating List" << std::endl;
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
	//std::cout << "INFO: Added instance of " << addData << std::endl;
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
			while (cIdx != idx) {
				temp = curr;
				curr = curr->next;
				cIdx++;
			}
			temp->next = newNode;
			newNode->next = curr;
		}
		//std::cout << "INFO: Added instance of " << addData << std::endl;
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
		//std::cout << "INFO: Removed instance of " << delData << std::endl;
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
		while (cIdx != idx) {
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

void List::UpdateIndex(int newData, int idx) {
	int length = FindLength();
	curr = head;
	int cIdx = 0;

	if (idx >= length or idx < 0) {
		std::cout << "UPDATE ERROR: Index " << idx << " is outwith list bounds" << std::endl;
	}
	else {
		while (cIdx != idx) {
			curr = curr->next;
			cIdx++;
		}
		curr->data = newData;
	}
}

void List::Reverse() {
	curr = head;
	temp = curr->next;
	curr->next = NULL;

	while (temp != NULL) {
		node* prev = temp->next;
		temp->next = curr;
		curr = temp;
		temp = prev;
	}
	head = curr;
}

void List::PrintList() {
	curr = head;

	std::cout << "List: ";
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

void List::PrintStructure() {
	curr = head;
	temp = curr;

	while (curr != NULL) {
		if (curr == head) {
			std::cout << "List Structure: |" << curr->data << ": " << &curr->data << "|";
		}
		else {
			std::cout << "--" << temp->next << "-->  " <<"|" << curr->data << ": " << &curr->data << "|";
		}
		temp = curr;
		curr = curr->next;
	}
	std::cout << "--" << temp->next << "-->  ";
	std::cout << std::endl;
}

int List::FindLength() {
	curr = head;
	int idx = 0;

	while (curr != NULL) {
		curr = curr->next;
		idx++;
	}
	return idx;
}

int List::AccessIndex(int idx) {
	int length = FindLength();
	curr = head;
	int cIdx = 0;

	if (idx >= length or idx < 0) {
		std::cout << "ACCESS ERROR: Index " << idx << " is outwith list bounds" << std::endl;
		return -1;
	}
	else {
		while (cIdx != idx) {
			curr = curr->next;
			cIdx++;
		}
		return curr->data;
	}
}

int* List::ConvertToArray() {
	int length = FindLength();
	int* array = new int[length];
	curr = head;
	int cIdx = 0;

	while (curr != NULL) {
		array[cIdx] = curr->data;
		curr = curr->next;
		cIdx++;
	}
	return array;
}
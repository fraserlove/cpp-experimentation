#include <iostream>

#include "list.h"

template <class T>
List<T>::List() {
	initPtrs();
}

template <class T>
List<T>::List(T initArray[], int size) {
	initPtrs();
	for (int i = 0; i < size; i++) {
		AddNode(initArray[i]);
	}
}

template <class T>
List<T>::~List () {
	curr = head;
	temp = curr;
	while (curr != NULL) {
		temp = curr->next;
		delete curr;
		curr = temp;
	}
	head = NULL;
}

template <class T>
void List<T>::initPtrs() {
	head = NULL;
	curr = NULL;
	temp = NULL;
}

template <class T>
void List<T>::AddNode(T data) {
	node* newNode = new node;
	newNode->next = NULL;
	newNode->data = data;
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
}

template <class T>
void List<T>::AddNode(int idx, T data) {
	int length = Length();
	if (idx == length) {
		AddNode(data);
	}
	else if (idx > length-1 || idx < 0) {
		std::cout << "ERROR: Index " << idx << " outwith list bounds" << std::endl;
	}
	else {
		node* newNode = new node;
		newNode->data = data;
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
	}
}

template <class T>
void List<T>::RemoveValue(T data) {
	node* delPtr = NULL;
	temp = head;
	curr = head;
	while (curr != NULL && curr->data != data) {
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL) {
		std::cout << "ERROR: No instance of " << data << " found" << std::endl;
	}
	else {
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;

		if (delPtr == head) {
			head = head->next;
			temp = NULL;
		}
	}
	delete delPtr;
}

template <class T>
void List<T>::DeleteNode(int idx) {
	int length = Length();
	node* delPtr = NULL;
	temp = head;
	curr = head;
	if (idx >= length || idx < 0) {
		std::cout << "ERROR: Index " << idx << " outwith list bounds" << std::endl;
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
	delete delPtr;

}

template <class T>
void List<T>::Update(int idx, T data) {
	int length = Length();
	curr = head;
	int cIdx = 0;
	if (idx >= length || idx < 0) {
		std::cout << "ERROR: Index " << idx << " outwith list bounds" << std::endl;
	}
	else {
		while (cIdx != idx) {
			curr = curr->next;
			cIdx++;
		}
		curr->data = data;
	}
}

template <class T>
void List<T>::Reverse() {
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

template <class T>
void List<T>::Show() {
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

template <class T>
void List<T>::ShowDebug() {
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

template <class T>
int List<T>::Length() {
	curr = head;
	int idx = 0;
	while (curr != NULL) {
		curr = curr->next;
		idx++;
	}
	return idx;
}

template <class T>
int List<T>::Access(int idx) {
	int length = Length();
	curr = head;
	int cIdx = 0;
	if (idx >= length || idx < 0) {
		std::cout << "ERROR: Index " << idx << " outwith list bounds" << std::endl;
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

template <class T>
int* List<T>::ToArray() {
	int length = Length();
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

// Template Definitions
template class List<int>;
template class List<float>;
template class List<char>;
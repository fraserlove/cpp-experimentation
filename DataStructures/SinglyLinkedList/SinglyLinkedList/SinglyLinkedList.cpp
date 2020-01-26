#include <iostream>

#include "SinglyLinkedList.h"

template <class T>
SinglyLinkedList<T>::SinglyLinkedList() {
	head = NULL;
	len = 0;
}

template <class T>
SinglyLinkedList<T>::SinglyLinkedList(T data[], int size) {
	head = NULL;
	len = 0;
	for (int i = 0; i < size; i++) {
		AddNode(data[i]);
	}
}

template <class T>
SinglyLinkedList<T>::~SinglyLinkedList () {
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
void SinglyLinkedList<T>::AddNode(T data) {
	Node* new_node = new Node;
	new_node->next = NULL;
	new_node->data = data;
	if (head != NULL) {
		curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = new_node;
	}
	else {
		head = new_node;
	}
	len++;
}

template <class T>
void SinglyLinkedList<T>::AddNode(int idx, T data) {
	int length = Length();
	if (idx == length) {
		AddNode(data);
	}
	else if (idx > length-1 || idx < 0) {
		std::cout << "ERROR: Index " << idx << " outwith list bounds" << std::endl;
	}
	else {
		Node* new_node = new Node;
		new_node->data = data;
		if (idx == 0) {
			new_node->next = head;
			head = new_node;
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
			temp->next = new_node;
			new_node->next = curr;
		}
		len++;
	}
}

template <class T>
void SinglyLinkedList<T>::RemoveValue(T data) {
	Node* del_ptr = NULL;
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
		del_ptr = curr;
		curr = curr->next;
		temp->next = curr;

		if (del_ptr == head) {
			head = head->next;
			temp = NULL;
		}
		len--;
	}
	delete del_ptr;
}

template <class T>
void SinglyLinkedList<T>::DeleteNode(int idx) {
	int length = Length();
	Node* del_ptr = NULL;
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
		del_ptr = curr;
		curr = curr->next;
		temp->next = curr;
		if (del_ptr == head) {
			head = head->next;
			temp = NULL;
		}
		len--;
	}
	delete del_ptr;

}

template <class T>
void SinglyLinkedList<T>::Update(int idx, T data) {
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
void SinglyLinkedList<T>::Clear() {
	curr = head;
	while (curr != NULL) {
		Node* del_ptr = NULL;
		del_ptr = curr;
		curr = curr->next;
		del_ptr->next == NULL;
		del_ptr->data == NULL;
		delete del_ptr;
	}
	head = NULL;
	temp = NULL;
	len = 0;
}

template <class T>
void SinglyLinkedList<T>::Reverse() {
	curr = head;
	temp = curr->next;
	curr->next = NULL;

	while (temp != NULL) {
		Node* prev = temp->next;
		temp->next = curr;
		curr = temp;
		temp = prev;
	}
	head = curr;
}

template <class T>
void SinglyLinkedList<T>::Show() {
	curr = head;
	while (curr != NULL) {
		if (curr == head) {
			std::cout << "List: " << curr->data;
		}
		else {
			std::cout << ", " << curr->data;
		}
		curr = curr->next;
	}
	std::cout << std::endl;
}

template <class T>
void SinglyLinkedList<T>::ShowDebug() {
	curr = head;
	while (curr != NULL) {
		if (curr == head) {
			std::cout << "List Structure: |" << curr->data << ": " << &curr->data << "|" << "--" << curr->next << "-->  ";
		}
		else {
			std::cout << "|" << curr->data << ": " << &curr->data << "|" << "--" << curr->next << "-->  ";
		}
		curr = curr->next;
	}
	std::cout << std::endl;
}

template <class T>
int SinglyLinkedList<T>::Length() {
	return len;
}

template <class T>
int SinglyLinkedList<T>::Access(int idx) {
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
int* SinglyLinkedList<T>::ToArray() {
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
template class SinglyLinkedList<int>;
template class SinglyLinkedList<float>;
template class SinglyLinkedList<char>;
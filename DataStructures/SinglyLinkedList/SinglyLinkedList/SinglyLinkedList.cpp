#include <iostream>

#include "SinglyLinkedList.h"

template <class T>
SinglyLinkedList<T>::SinglyLinkedList() {
	head = tail = NULL;
	len = 0;
}

template <class T>
SinglyLinkedList<T>::SinglyLinkedList(T data[], int size) {
	head = tail = NULL;
	len = 0;
	for (int i = 0; i < size; i++) {
		Add(data[i]);
	}
}

template <class T>
SinglyLinkedList<T>::~SinglyLinkedList () {
	temp = curr = head;
	len = 0;
	while (curr != NULL) {
		temp = curr->next;
		delete curr;
		curr = temp;
	}
	head = tail = NULL;
}

template <class T>
void SinglyLinkedList<T>::Set(int idx, T data) {
	curr = head;
	int cIdx = 0;
	if (idx >= len || idx < 0 || IsEmpty()) {
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
void SinglyLinkedList<T>::Add(T data) {
	Node* new_node = new Node;
	new_node->next = NULL;
	new_node->data = data;
	if (head != NULL) {
		tail->next = new_node;
	}
	else {
		head = tail = new_node;
	}
	tail = new_node;
	len++;
}

template <class T>
void SinglyLinkedList<T>::Add(int idx, T data) {
	if (idx == len) {
		Add(data);
	}
	else if (idx > len - 1 || idx < 0) {
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
			temp = curr = head;
			int cIdx = 0;
			while (cIdx != idx) {
				temp = curr;
				curr = curr->next;
				cIdx++;
			}
			temp->next = new_node;
			new_node->next = curr;
		}
		tail = new_node;
		len++;
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
	head = tail = NULL;
	len = 0;
}

template <class T>
void SinglyLinkedList<T>::Reverse() {
	if (IsEmpty()) {
		std::cout << "ERROR: List is empty" << std::endl;
	}
	else {
		tail = curr = head;
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
}

template <class T>
void SinglyLinkedList<T>::Show() {
	curr = head;
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
void SinglyLinkedList<T>::ShowAsString(){
	curr = head;
	while (curr != NULL) {
		std::cout << curr->data;
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
	std::cout << std::endl << "Tail: " << tail << std::endl;
}

template <class T>
int SinglyLinkedList<T>::Length() { return len; }

template <class T>
int SinglyLinkedList<T>::Find(T data) {
	temp = curr = head;
	for (int i = 0; i < len; i++) {
		if (curr->data != data) {
			curr = curr->next;
		}
		else {
			return i;
		}
	}
	return -1;
}

template <class T>
int* SinglyLinkedList<T>::ToArray() {
	int* array = new int[len];
	curr = head;
	int cIdx = 0;
	while (curr != NULL) {
		array[cIdx] = curr->data;
		curr = curr->next;
		cIdx++;
	}
	return array;
}

template <class T>
bool SinglyLinkedList<T>::IsEmpty() { return Length() == 0; }

template <class T>
bool SinglyLinkedList<T>::RemoveValue(T data) {
	temp = curr = head;
	while (curr != NULL && curr->data != data) {
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL) {
		return false;
	}
	else {
		Node* del_ptr = curr;
		curr = curr->next;
		temp->next = curr;
		if (del_ptr == head) {
			head = head->next;
		}
		else if (del_ptr == tail) {
			tail = temp;
		}
		delete del_ptr;
		len--;
		return true;
	}
}

template <class T>
bool SinglyLinkedList<T>::Contains(T data) { return Find(data) != -1; }

template <class T>
T SinglyLinkedList<T>::Access(int idx) {
	curr = head;
	int cIdx = 0;
	if (idx >= len || idx < 0 || IsEmpty()) {
		std::cout << "ERROR: Index " << idx << " outwith list bounds" << std::endl;
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
T SinglyLinkedList<T>::Peek() {
	if (IsEmpty()) {
		std::cout << "ERROR: List is empty" << std::endl;
	}
	else {
		return head->data;
	}
}

template <class T>
T SinglyLinkedList<T>::Remove(int idx) {
	temp = curr = head;
	if (idx >= len || idx < 0 || IsEmpty()) {
		std::cout << "ERROR: Index " << idx << " outwith list bounds" << std::endl;
	}
	else {
		Node* del_ptr;
		if (idx == 0) {
			del_ptr = head;
			head = head->next;
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
			if (del_ptr == tail) {
				tail = temp;
			}
		}
		T r_data = del_ptr->data;
		delete del_ptr;
		len--;
		return r_data;
	}
}

template class SinglyLinkedList<int>;
template class SinglyLinkedList<float>;
template class SinglyLinkedList<char>;
#include <iostream>

#include "PriorityQueue.h"

template <class T>
PQueue<T>::PQueue() {
	heap = new DynamicArray<T>(1);
}

template <class T>
PQueue<T>::PQueue(int size) {
	heap = new DynamicArray<T>(size);
}

template <class T>
PQueue<T>::PQueue(T data[], int size) {
	heap = new DynamicArray<T>(size);
	for (int i = 0; i < size; i++) {
		heap->Push(data[i]);
	}
	for (int i = 0; i < (size / 2) - 1; i++) {
		HeapifyDown(i);
	}
}

template <class T>
PQueue<T>::~PQueue() { delete heap; }

template <class T>
void PQueue<T>::Enqueue(T data) {
	heap->Push(data);
	HeapifyUp(Length() - 1);
}

template <class T>
void PQueue<T>::Clear() {
	heap->~DynamicArray();
	delete heap;
}

template <class T>
void PQueue<T>::ShowDebug() {
	std::cout << "Heap: ";
	heap->ShowDebug();
}

template <class T>
int PQueue<T>::Length() { return heap->Length(); }

template <class T>
bool PQueue<T>::IsEmpty() { return Length() == 0; }

template <class T>
bool PQueue<T>::RemoveValue(T data) {
	for (int i = 0; i < Length(); i++) {
		if (heap->Access(i) == data) {
			Remove(i);
			return true;
		}
	}
	return false;
}

template <class T>
bool PQueue<T>::Contains(T data) {
	// Hash table lookup needed for O(1)
	for (int i = 0; i < Length(); i++) {
		if (heap->Access(i) == data) {
			return true;
		}
	}
	return false;
}

template <class T>
bool PQueue<T>::IsMin(int idx) {
	if (Length() > 1) {
		if (idx >= Length()) {
			return true;
		}
		int l_idx = 2 * idx + 1;
		int r_idx = 2 * idx + 2;
		if ((l_idx < Length() && !Less(idx, l_idx)) || (r_idx < Length() && !Less(idx, r_idx))) {
			return false;
		}
		return IsMin(l_idx) && IsMin(r_idx);
	}
	else {
		std::cout << "ERROR: Heap to small to determine nature" << std::endl;
		return false;
	}
}

template <class T>
T PQueue<T>::Dequeue() {
	return Remove(0);
}

template <class T>
T PQueue<T>::Peek() {
	return heap->Access(0);
}

/* Private Methods */

template <class T>
void PQueue<T>::HeapifyUp(int idx) {
	int parent_idx = Parent(idx);
	while (idx > 0 && Less(idx, parent_idx)) {
		Swap(parent_idx, idx);
		idx = parent_idx;
		parent_idx = Parent(idx);
	}
}

template <class T>
void PQueue<T>::HeapifyDown(int idx) {
	int l_idx = LeftChild(idx);
	int r_idx = RightChild(idx);
	int min_idx = idx;
	if ((l_idx < Length()) && Less(l_idx, min_idx)) {
		min_idx = l_idx;
	}
	if ((r_idx < Length()) && Less(r_idx, min_idx)) {
		min_idx = r_idx;
	}
	if (min_idx != idx) {
		Swap(min_idx, idx);
		HeapifyDown(min_idx);
	}
}

template <class T>
void PQueue<T>::Swap(int idx_1, int idx_2) {
	T node_1 = heap->Access(idx_1);
	T node_2 = heap->Access(idx_2);
	heap->Set(idx_1, node_2);
	heap->Set(idx_2, node_1);
}

template <class T>
int PQueue<T>::Parent(int idx) { return (idx - 1) / 2; }

template <class T>
int PQueue<T>::LeftChild(int idx) { return 2 * idx + 1; }

template <class T>
int PQueue<T>::RightChild(int idx) { return 2 * idx + 2; }

template <class T>
bool PQueue<T>::Less(int idx_1, int idx_2) {
	T node_1 = heap->Access(idx_1);
	T node_2 = heap->Access(idx_2);
	return (node_1 <= node_2);
}

template <class T>
T PQueue<T>::Remove(int idx) {
	if (IsEmpty()) {
		std::cout << "ERROR: Priority Queue is empty" << std::endl;
	}
	else {
		T r_data = heap->Access(idx);
		Swap(idx, Length() - 1);
		heap->Remove(Length() - 1);
		if (idx == Length()) {
			return r_data;
		}
		T data = heap->Access(idx);
		HeapifyDown(idx);
		if (data == heap->Access(idx)) {
			HeapifyUp(idx);
		}
		return r_data;
	}
}

// Template Definitions
template class PQueue<int>;
template class PQueue<float>;
template class PQueue<char>;
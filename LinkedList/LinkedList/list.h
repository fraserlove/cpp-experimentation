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

	void initPtrs();

public:
	List();
	List(int initArray[], int size);
	~List();

	void AddNode(int addData);
	void AddNode(int addData, int idx);

	void DeleteNodeByInstance(int delData);
	void DeleteNodeByIndex(int idx);

	void UpdateIndex(int newData, int idx);

	void PrintList();

	int FindLength();
	int AccessIndex(int idx);
	int* ConvertToArray();
}; 
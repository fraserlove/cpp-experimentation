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
	int FindLength();
	void PrintList();
	//int AccessIndex() return value;
}; 
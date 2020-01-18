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

public:

	List();
	~List();
	void AddNode(int addData);
	void DeleteNode(int delData);
	void InsertNode(int instData, int idx);
	int FindLength();
	void PrintList();

}; 
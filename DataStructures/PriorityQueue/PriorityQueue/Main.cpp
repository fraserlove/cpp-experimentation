#include <iostream>

#include "PriorityQueue.h"

typedef char type;

void PrintHeader() {
	std::cout << " Priority Queue Data Structure Implementation using Binary Heaps" << std::endl;
	std::cout << " Author: Fraser Love, me@fraserlove.com" << std::endl;
	std::cout << " Latest Release: 31/01/20" << std::endl;
	std::cout << " MIT Licience - Copyright (c) 2020 Fraser Love" << std::endl;
	std::cout << std::endl << " Entered Test Console. Type \"list\" for commands or \"quit\" to exit" << std::endl << std::endl;
}

void Console(PQueue<type>* pqueue) {
	bool session = true;
	std::string cmd;
	PrintHeader();
	while (session) {
		std::cout << " > ";
		std::cin >> cmd;
		if (cmd == "quit") {
			session = false;
		}
		if (cmd == "list") {
			std::cout << " All Commands (Must be entered lower case):" << std::endl << std::endl;
			std::cout << "     enqueue {value}" << std::endl << "     remove_value {value}" << std::endl << "     contains {value}" << std::endl;
			std::cout << "     dequeue" << std::endl << "     peek" << std::endl << "     clear" << std::endl;
			std::cout << "     show_debug" << std::endl << "     length" << std::endl << "     is_empty" << std::endl << "     contains" << std::endl;
			std::cout << "     is_max" << std::endl << "     is_min" << std::endl << "     vaild_heap" << std::endl << std::endl;
		}
		if (cmd == "enqueue") {
			std::cin >> cmd;
			pqueue->Enqueue(cmd[0]);
		}
		if (cmd == "dequeue") {
			std::cout << " " << pqueue->Dequeue() << std::endl;
		}
		if (cmd == "remove_value") {
			std::cin >> cmd;
			pqueue->RemoveValue(cmd[0]);
		}
		if (cmd == "peek") {
			std::cout << " " << pqueue->Peek() << std::endl;
		}
		if (cmd == "clear") {
			pqueue->Clear();
		}
		if (cmd == "show_debug") {
			std::cout << " ";
			pqueue->ShowDebug();
		}
		if (cmd == "length") {
			std::cout << " " << pqueue->Length() << std::endl;
		}
		if (cmd == "is_empty") {
			std::cout << " " << pqueue->IsEmpty() << std::endl;
		}
		if (cmd == "contains") {
			std::cin >> cmd;
			std::cout << " " << pqueue->Contains(cmd[0]) << std::endl;
		}
		if (cmd == "is_max") {
			std::cout << " " << pqueue->IsMax() << std::endl;
		}
		if (cmd == "is_min") {
			std::cout << " " << pqueue->IsMin() << std::endl;
		}
		if (cmd == "valid_heap") {
			std::cout << " " << pqueue->ValidHeap() << std::endl;
		}
	}
}

int main() {
	PQueue<type> pqueue;
	Console(&pqueue);
}
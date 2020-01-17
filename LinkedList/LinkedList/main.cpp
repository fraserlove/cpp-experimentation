#include "list.h"

int main() {

	List fibonacci;
	fibonacci.AddNode(1);
	fibonacci.AddNode(1);
	fibonacci.AddNode(2);
	fibonacci.AddNode(3);
	fibonacci.AddNode(5);
	fibonacci.PrintList();
	fibonacci.DeleteNode(5);
	fibonacci.PrintList();

}
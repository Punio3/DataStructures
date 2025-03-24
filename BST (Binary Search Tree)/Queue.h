#include "Node.h"

class Queue {
public:
	Node* First;
	Node* Last;
	int Size;

	Queue();
	void push(leaf* Leaf);
	leaf* pop();
};
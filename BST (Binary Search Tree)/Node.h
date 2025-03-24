#include "leaf.h"

class Node {
public:
	leaf* ActualNode;
	Node* NextNode;

	Node();
	Node(leaf* Leaf);
};
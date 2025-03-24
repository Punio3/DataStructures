#include "Node.h"


Node::Node() {
	ActualNode = nullptr;
	NextNode = nullptr;
}
Node::Node(leaf* Leaf) {
	ActualNode = Leaf;
	NextNode = nullptr;
}
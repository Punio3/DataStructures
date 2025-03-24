#include "Node.h";

Node::Node() {
	character = '!';
	nextNode = nullptr;
}

Node::Node(char x) {
	character = x;
	nextNode = nullptr;
}
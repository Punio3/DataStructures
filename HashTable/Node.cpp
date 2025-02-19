#include "Node.h";

Node::Node() {
	student = nullptr;
	nextNode = nullptr;
}

Node::Node(Student* stud) {
	student = stud;
	nextNode = nullptr;
}
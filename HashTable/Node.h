#include "Student.h";

class Node {
public:
	Student* student;
	Node* nextNode;

	Node();
	Node(Student* student);
};
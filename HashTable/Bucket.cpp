#include "Bucket.h"

Bucket::Bucket() {
	FirstNode = nullptr;
	Size = 0;
}

void Bucket::AddNode(Student* stud) {
	Node* Actual = FirstNode;
	Node* prev = FirstNode;
	while (Actual!=nullptr) {
		prev = Actual;
		Actual = Actual->nextNode;
	}

	if (FirstNode == nullptr) FirstNode = new Node(stud);
	else prev->nextNode = new Node(stud);
	Size++;
}

Student* Bucket::Get(std::string Name) {
	Node* actual = FirstNode;

	while (actual != nullptr) {
		if (actual->student->Name == Name) break;
		actual = actual->nextNode;
	}

	if (actual == nullptr) return nullptr;
	else return actual->student;
}

void DeleteHelper(Node* actual) {
	if (actual != nullptr) {
		DeleteHelper(actual->nextNode);
		delete(actual->student);
		delete(actual);
	}

}

void Bucket::Delete() {
	DeleteHelper(FirstNode);
}

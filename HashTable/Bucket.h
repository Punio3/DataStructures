#include "Node.h";

class Bucket {
public:
	Node* FirstNode;
	int Size;

	Bucket();
	void AddNode(Student* stud);
	Student* Get(std::string Name);
	void Delete();
};
#include "Student.h";

Student::Student() {
	Name = "Jack";
	ID = "999";
}

Student::Student(std::string id, std::string name) {
	Name = name;
	ID = id;
}
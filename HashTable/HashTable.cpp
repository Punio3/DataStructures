#include "HashTable.h"

HashTable::HashTable(int size) {
	Size = size;
	buckets = new Bucket[size];
}

int HashTable::HashFunction(std::string Name) {
	int output = 0;
	int iterator = Name.size()-1;
	for (char x : Name) {
		int mul = x;
		for (int i = iterator; i >= 0; i--) {
			mul *= 31;
			mul %= Size;
		}
		iterator--;
		output += mul;
	}
	return output % Size;
}

void HashTable::Add(Student* student) {
	int number = HashFunction(student->Name);
	buckets[number].AddNode(student);
}

Student* HashTable::Get(std::string name) {
	int number = HashFunction(name);
	return buckets[number].Get(name);
}

void HashTable::Delete() {
	for (int k = 0; k < Size; k++) {
		buckets[k].Delete();
	}
	delete(buckets);
}
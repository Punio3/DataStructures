#include "Bucket.h"

class HashTable {
public:
	int Size;
	Bucket* buckets;

	HashTable(int Size);
	void Add(Student* stud);
	int HashFunction(std::string Name);
	Student* Get(std::string Name);
	void Delete();
};
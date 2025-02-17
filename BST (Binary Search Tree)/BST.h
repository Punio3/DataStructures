#include "leaf.h"

class BST {
public:
	leaf* Root;
	int Size;

	BST();
	void addNumber(int value);
	void ShowTreeInOrder();
	leaf* FindValue(int value);
	leaf* FindConsequent(leaf* leaf);
	void DeleteNumber(int value);
	void DeleteChildFromParent(leaf* Leaf);
};
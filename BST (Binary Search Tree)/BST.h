#pragma once
#include "Queue.h"

class BST {
public:
	leaf* Root;
	int Size;

	BST();
	void addNumber(int value);
	void ShowTreeInOrder();
	leaf* FindLeafToDelete(int value);
	void DeleteNumber(int value);
	void ShowTreeInPostOrder();
	void ShowTreeInPreOrder();
	void BFS();
	~BST();
};
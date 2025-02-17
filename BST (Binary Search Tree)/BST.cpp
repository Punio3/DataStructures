#pragma once
#include "BST.h"
#include <iostream>

BST::BST() {
	Root = nullptr;
	Size = 0;
}

void BST::addNumber(int value) {
	leaf* currentLeaf = Root;
	leaf* prevLeaf=nullptr;
	if (Root == nullptr) Root = new leaf(value);
	else {
		while (currentLeaf != nullptr) {
			if (currentLeaf->Value < value) {
				prevLeaf = currentLeaf;
				currentLeaf = currentLeaf->RightChild;
			}
			else {
				prevLeaf = currentLeaf;
				currentLeaf = currentLeaf->LeftChild;
			}
		}

		if (prevLeaf->Value > value) {
			prevLeaf->LeftChild = new leaf(value);
		}
		else {
			prevLeaf->RightChild = new leaf(value);
		}
	}
}

void ShowLeaf(leaf* current) {
	if (current != nullptr) {
		ShowLeaf(current->LeftChild);
		std::cout << current->Value << " ";
	}
	if(current!=nullptr && current->RightChild!=nullptr) ShowLeaf(current->RightChild);
}

void BST::ShowTreeInOrder() {
	ShowLeaf(Root);
	std::cout << std::endl;
}

leaf* BST::FindValue(int value) {
	leaf* current = Root;
	while (current->Value != value) {
		if (current->Value < value) {
			current = current->RightChild;
		}
		else {
			current = current->LeftChild;
		}
	}
	return current;
}

void BST::DeleteChildFromParent(leaf* Leaf) {
	leaf* current = Root;
	leaf* prev = current;
	while (current->Value != Leaf->Value) {
		if (current->Value < Leaf->Value) {
			prev = current;
			current = current->RightChild;
		}
		else {
			prev = current;
			current = current->LeftChild;
		}
	}
	if (prev->LeftChild != nullptr && prev->LeftChild->Value == Leaf->Value) prev->LeftChild = nullptr;
	else if (prev->RightChild != nullptr && prev->RightChild->Value == Leaf->Value) prev->RightChild = nullptr;
}

leaf* BST::FindConsequent(leaf* Leaf) {
	leaf* current = Leaf;
	if (Leaf->LeftChild == nullptr && Leaf->RightChild == nullptr) {
		DeleteChildFromParent(current);
		return current;
	}

	while (true) {
		if (current->RightChild == nullptr) {
			current = current->LeftChild;
			if (current->RightChild == nullptr) {
				Leaf->LeftChild = current->LeftChild;
				Leaf->Value = current->Value;
				return current;
			}
		}
		else {
			current = current->RightChild;
			if (current->LeftChild == nullptr) {
				Leaf->RightChild = current->RightChild;
				Leaf->Value = current->Value;
				return current;
			}
		}
	}

}

void BST::DeleteNumber(int value) {
	leaf* tmp=FindConsequent(FindValue(value));
	delete(tmp); 
}
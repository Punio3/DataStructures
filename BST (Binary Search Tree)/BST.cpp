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

void ShowLeafInOrder(leaf* current) {
	if (current != nullptr) {
		ShowLeafInOrder(current->LeftChild);
		std::cout << current->Value << " ";
	}
	if(current!=nullptr && current->RightChild!=nullptr) ShowLeafInOrder(current->RightChild);
}

void BST::ShowTreeInOrder() {
	ShowLeafInOrder(Root);
	std::cout << std::endl;
}

leaf* BST::FindLeafToDelete(int value) {
	leaf* current = Root;
	leaf* prev = current;
	//szukanie liscia o podanej wartosci
	while (current->Value != value) {
		if (current->Value < value) {
			prev = current;
			current = current->RightChild;
		}
		else {
			prev = current;
			current = current->LeftChild;
		}
	}
	

	leaf* Consequent = current;
	//usuniecie lisicia bez dzieci oraz zaaktualizowanie wskaznika u rodzica
	if (Consequent->LeftChild == nullptr && Consequent->RightChild == nullptr) {
		if (prev->LeftChild != nullptr && prev->LeftChild->Value == current->Value) prev->LeftChild = nullptr;
		else if (prev->RightChild != nullptr && prev->RightChild->Value == current->Value) prev->RightChild = nullptr;
		return current;
	}

	//szukanie nastepnika i aktualizowanie wskaznikow 
	while (true) {
		if (Consequent->RightChild == nullptr) {
			Consequent = Consequent->LeftChild;
			if (Consequent->RightChild == nullptr) {
				current->LeftChild = Consequent->LeftChild;
				current->Value = Consequent->Value;
				return Consequent;
			}
		}
		else {
			Consequent = Consequent->RightChild;
			if (Consequent->LeftChild == nullptr) {
				current->RightChild = Consequent->RightChild;
				current->Value = Consequent->Value;
				return Consequent;
			}
		}
	}
}

void BST::DeleteNumber(int value) {
	leaf* tmp = FindLeafToDelete(value);
	delete(tmp); 
}


void ShowLeafPostOrder(leaf* current) {
	if (current != nullptr) {
		ShowLeafPostOrder(current->LeftChild);
		ShowLeafPostOrder(current->RightChild);
		std::cout << current->Value << " ";
	}
}

void BST::ShowTreeInPostOrder() {
	ShowLeafPostOrder(Root);
	std::cout << std::endl;
}

void ShowLeafPreOrder(leaf* current) {
	if (current != nullptr) {
		std::cout << current->Value << " ";
		ShowLeafPreOrder(current->LeftChild);
		ShowLeafPreOrder(current->RightChild);
	}
}

void BST::ShowTreeInPreOrder() {
	ShowLeafPreOrder(Root);
	std::cout << std::endl;
}

void BST::BFS() {
	Queue queue = Queue();
	leaf* PoppedLeaf;
	queue.push(Root);
	while (queue.Size != 0) {
		PoppedLeaf = queue.pop();
		if (PoppedLeaf->LeftChild != nullptr) queue.push(PoppedLeaf->LeftChild);
		if (PoppedLeaf->RightChild != nullptr) queue.push(PoppedLeaf->RightChild);
		std::cout << PoppedLeaf->Value << " ";
	}
	std::cout << std::endl;
}

void DeleteLeaf(leaf* current) {
	if (current != nullptr) {
		DeleteLeaf(current->LeftChild);
		DeleteLeaf(current->RightChild);
		delete(current);
	}
}

BST::~BST() {
	DeleteLeaf(Root);
}
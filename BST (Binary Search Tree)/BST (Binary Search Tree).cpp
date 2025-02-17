#include <iostream>
#include "BST.h";
using namespace std;

void DisplayOperations() {
	cout << "1)Dodaj wartosc\n2)Usun wartosc\n3)Wyswietl In Order\n";
}

void OperationLoopInTree() {
	int value=0;
	int option=0;
	BST BinarySearchTree= BST();

	while (option != -1) {
		DisplayOperations();
		cin >> option;
		switch (option) {
			case 1:
				cout << "Podaj wartosc: ";
				cin >> value;
				BinarySearchTree.addNumber(value);
				break;
			case 2:
				cin >> value;
				BinarySearchTree.DeleteNumber(value);
				break;
			case 3:
				BinarySearchTree.ShowTreeInOrder();
		}
	}
}

int main()
{
	OperationLoopInTree();
}

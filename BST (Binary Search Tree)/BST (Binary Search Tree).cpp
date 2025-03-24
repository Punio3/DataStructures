#include <iostream>
#include "BST.h";
using namespace std;

void DisplayOperations() {
	cout << "1)Dodaj wartosc\n2)Usun wartosc\n3)Wyswietl InOrder\n4)Wyswietl PreOrder\n5)Wyswietl PostOrder\n6)Wyswietl BFS\n7)Usuniecie struktury\n";
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
				break;
			case 4:
				BinarySearchTree.ShowTreeInPreOrder();
				break;
			case 5:
				BinarySearchTree.ShowTreeInPostOrder();
				break;
			case 6:
				BinarySearchTree.BFS();
				break;
			case 7:
				BinarySearchTree.~BST();
				break;
		}
	}
}

int main()
{
	OperationLoopInTree();
}

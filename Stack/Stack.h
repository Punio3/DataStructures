#include "Node.h";
#include<iostream>

class Stack {
public:
	Node* Top;
	int Size;

	Stack();
	void push(char character);
	char pop();
	void Delete();
	void ShowStack();
	char Peek();
};
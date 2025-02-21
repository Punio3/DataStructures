#include "Stack.h";

Stack::Stack() {
	Top = nullptr;
	Size = 0;
}

void Stack::push(char character) {
	Node* newNode = new Node(character);
	if (Top == nullptr) {
		Top = newNode;
	}
	else {
		newNode->nextNode = Top;
		Top = newNode;
	}
	Size++;
}

char Stack::pop() {
	Node* actual = Top;
	char output;

	if (actual == nullptr) {
		return '!';
	}
	else {
		Top = actual->nextNode;
		output = actual->character;
		delete(actual);
		Size--;
		return output;
	}

}

void Stack::Delete() {
	while (Size != 0) {
		pop();
	}
}

void Stack::ShowStack() {
	Node* Actual = Top;
	int iterator = 1;
	std::cout << "Stack: \n";
	while (Actual != nullptr) {
		std::cout << iterator << ": " << Actual->character<<"\n";
		Actual = Actual->nextNode;
		iterator++;
	}
}
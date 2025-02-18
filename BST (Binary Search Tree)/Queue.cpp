#include "Queue.h"

Queue::Queue() {
	First = nullptr;
	Last = nullptr;
	Size = 0;
}

void Queue::push(leaf* Leaf) {
	Node* NewNode = new Node(Leaf);
	
	if (First == nullptr) First = NewNode;
	if (Last == nullptr) Last = NewNode;
	else {
		Last->NextNode = NewNode;
		Last = NewNode;
	}
	Size++;
}

leaf* Queue::pop() {
	leaf* tmp=nullptr;
	Node* FirstNode;
	if (First != nullptr) {
		tmp = First->ActualNode;
		FirstNode = First;
		First = First->NextNode;

		delete(FirstNode);
		Size--;
	}	
	if (Size == 0) {
		First = nullptr;
		Last = nullptr;
	}
	
	return tmp;
}
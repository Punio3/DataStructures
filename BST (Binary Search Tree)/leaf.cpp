#include "leaf.h"

leaf::leaf() {
	Value = -1;
	LeftChild = nullptr;
	RightChild = nullptr;
}

leaf::leaf(int value) {
	Value = value;
	LeftChild = nullptr;
	RightChild = nullptr;
}
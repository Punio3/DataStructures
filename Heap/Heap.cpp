#include "Heap.h"


Heap::Heap(int capacity, HeapType type) : Capacity(capacity), Type(type), Size(0) {
    HeapArray = new int[Capacity];
}

Heap::Heap() : Heap(10, Min) {}

void Heap::Swap(int index1, int index2) {
    int temp = HeapArray[index1];
    HeapArray[index1] = HeapArray[index2];
    HeapArray[index2] = temp;
  //  std::cout << HeapArray[index1] << "  " << HeapArray[index2]<<std::endl;
}

void Heap::Insert(int number) {
    if (Size == Capacity) {
        Resize();
    }
    HeapArray[Size] = number;
    HeapifyUp(Size);
    Size++;
}

void Heap::Remove() {
    if (Size == 0) return;
    HeapArray[0] = HeapArray[Size - 1];
    Size--;
    HeapifyDown(0);
}

void Heap::Resize() {
    Capacity *= 2;
    int* newArray = new int[Capacity];
    for (int i = 0; i < Size; i++) {
        newArray[i] = HeapArray[i];
    }
    delete[] HeapArray;
    HeapArray = newArray;
}

void Heap::HeapifyUp(int index) {
    while (index > 0 && ((Type == Min && HeapArray[index] < HeapArray[Parent(index)]) ||
        (Type == Max && HeapArray[index] > HeapArray[Parent(index)]))) {
        Swap(index, Parent(index));
        index = Parent(index);
    }
}

void Heap::HeapifyDown(int index) {
    int left = LeftChild(index);
    int right = RightChild(index);
    int extreme = index;

    if (left < Size && ((Type == Min && HeapArray[left] < HeapArray[extreme]) ||
        (Type == Max && HeapArray[left] > HeapArray[extreme]))) {
        extreme = left;
    }
    if (right < Size && ((Type == Min && HeapArray[right] < HeapArray[extreme]) ||
        (Type == Max && HeapArray[right] > HeapArray[extreme]))) {
        extreme = right;
    }
    if (extreme != index) {
        Swap(index, extreme);
        HeapifyDown(extreme);
    }
}

void Heap::Print() {
    for (int i = 0; i < Size; i++) {
        std::cout << HeapArray[i] << std::endl;
    }
    std::cout << std::endl;
}

void Heap::HeapSort() {
    int originalSize = Size;
    while (Size > 1) {
        Swap(0, Size - 1);
        Size--;
        HeapifyDown(0);
    }
    Size = originalSize;
}
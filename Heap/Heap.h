#include <iostream>

enum HeapType {
	Min,
	Max
};

class Heap {
public:
    int* HeapArray;
    int Size;
    int Capacity;
    HeapType Type;

    Heap(int capacity, HeapType type);
    Heap();

    void Insert(int number);
    void Remove();
    void Resize();
    void Print();
    void HeapSort();
private:
    void HeapifyUp(int index);
    void HeapifyDown(int index);
    void Swap(int index1, int index2);
    int Parent(int index) { return (index - 1) / 2; }
    int LeftChild(int index) { return 2 * index + 1; }
    int RightChild(int index) { return 2 * index + 2; }
};
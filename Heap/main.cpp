#include "Heap.h"
using namespace std;

void Menu() {
    cout << "Podaj opcje:\n1)Dodaj do heapa\n2)Usun z Heapa\n3)Wypisz Heapa\n4)Heap sort\n5)Dodaj automatycznie liczby\n6)Usun strukture\n";
}

void InsertHeap(Heap* heap) {
    int number;
    cout << "Podaj liczbe: ";
    cin >> number;
    heap->Insert(number);
}

void AddNumbersToHeap(Heap* heap) {
    int amount;
    cout << "Podaj ilosc liczb: ";
    cin >> amount;

    for (int k = 0; k < amount; k++) {
        int rnd = rand();
       // cout << "rnd: " << rnd << endl;
        heap->Insert(rnd);

    }
}

void GameLoop() {
    int option = 0;
    int size;
    int type;
    Heap heap;
    cout << "Podaj rozmiar heapa: ";
    cin >> size;
    cout << "Podaj typ heapa(1 - minHeap, 2 - maxHeap): ";
    cin >> type;
    if (type == 1) heap = Heap(size, Min);
    else if (type == 2) heap = Heap(size, Max);

    while (true) {
        Menu();
        cin >> option;
        switch (option) {
        case 1:
            InsertHeap(&heap);
            break;
        case 2:
            heap.Remove();
            break;
        case 3:
            heap.Print();
            break;
        case 4:
            heap.HeapSort();
            break;
        case 5:
            AddNumbersToHeap(&heap);
            break;
        case 6:
            heap.~Heap();
            return;
        }
    }
}

int main()
{
    GameLoop();
}

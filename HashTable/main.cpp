#include <iostream>
using namespace std;
#include "HashTable.h"

void ShowMenu() {
	cout << "Wybierz opcje\n1)Dodaj studenta\n2)Znajdz ID studenta\n3)Automatyczne dodanie studentow\n4)Zakoncz program\n";
}

Student* CreateStudent() {
	string Name;
	string ID;

	cout << "Podaj nazwe: ";
	cin >> Name;
	cout << "Podaj ID: ";
	cin >> ID;

	return new Student(ID, Name);
}

std::string GetStudentName() {
	std::string name;
	cin >> name;
	return name;
}

std::string generateRandomString(int length = 8) {
	std::string str;
	static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < length; ++i) {
		str += charset[rand() % (sizeof(charset) - 1)];
	}
	return str;
}

std::string generateRandomID(int length = 6) {
	std::string id;
	for (int i = 0; i < length; ++i) {
		id += '0' + rand() % 10; 
	}
	return id;
}

void AutomaticAddingStudents(HashTable* hashtable) {
	int amount;
	cout << "Podaj ilosc studentow: ";
	cin >> amount;
	for (int k = 0; k < amount; k++) {
		hashtable->Add(new Student(generateRandomID(), generateRandomString()));
	}
}

void LoopGame() {
	int option = 0;
	int size = 0;
	
	cout << "Podaj rozmiar HashTable: ";
	cin >> size;
	HashTable _HashTable = HashTable(size);

	while (true) {
		ShowMenu();
		cin >> option;
		switch (option) {
		case 1:
			_HashTable.Add(CreateStudent());
			break;
		case 2:
			cout <<"Jego ID to: "<< _HashTable.Get(GetStudentName())->ID << endl;
			break;
		case 3:
			AutomaticAddingStudents(&_HashTable);
			break;
		case 4:
			_HashTable.Delete();
			return;
		}
	}
}

int main()
{
	LoopGame();
}


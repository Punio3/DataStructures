#include "Stack.h"
using namespace std;


void ShowMenu() {
	cout << "Wybierz opcje:\n1)Dodaj na stacka\n2)Usun ze stacka\n3)Wypisz caly stack\n4)Usun cala strukture\n";
}

void DodajNaStack(Stack* stack) {
	char tmp;
	cin >> tmp;

	stack->push(tmp);
}


void GameLoop() {
	int option = 0;
	Stack stack = Stack();

	while (true) {
		ShowMenu();
		cin >> option;

		switch (option) {
		case 1:
			DodajNaStack(&stack);
			break;
		case 2:
			cout<<"Usunieto ze stacka: "<<stack.pop()<<endl;
			break;
		case 3:
			stack.ShowStack();
			break;
		case 4:
			stack.Delete();
			return;
		}
	}
}

bool CompareToCharacters(char first, char second) {
	if (first == '(') {
		if (second == ')') return true;
		else return false;
	}
	else if (first == '[') {
		if (second == ']') return true;
		else return false;
	}
	else if (first == '{') {
		if (second == '}') return true;
		else return false;
	}
}

void SzukaniePoprawnychNawiasow() {
	string CiagZnakow;
	Stack stack;

	cout << "Podaj ciag znakow: ";
	cin >> CiagZnakow;

	for (char x : CiagZnakow) {
		if (x == '}' || x == ']' || x == ')') {
			if (stack.Size == 0) {
				cout << "Bledny ciag nawiasow" << endl;
				stack.Delete();
				return;
			}
			else {
				if (CompareToCharacters(stack.Peek(), x)) {
					stack.pop();
				}
				else {
					cout << "Bledny ciag znakow"<<endl;
					stack.Delete();
					return;
				}
			}
		}
		else if(x == '{' || x == '(' || x == '['){
			stack.push(x);
		}
	}
	if (stack.Size == 0) {
		cout << "Poprawny ciag znakow" << endl;
	}
	else {
		cout << "Bledny ciag znakow" << endl;
	}
	stack.Delete();
}


int main()
{
	//GameLoop();
	while (true) {
		SzukaniePoprawnychNawiasow();
	}
}


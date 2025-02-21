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

int main()
{
	GameLoop();
}


//
// Created by vhund on 24.03.2019.
//
#include "../Lib/Stack.h"
#include <iostream>

using namespace std;

void clearBuff() {       ///< @brief Чистит буфер
	cin.clear();           // Restore input stream to working state
	cin.ignore(4276, '\n'); // Get rid of any garbage that user might have entered}
}

int main() {
	int tmp;
	cout << "Какой тип элементов массива? \n 1)float\n 2)unsigned char" << endl;
	cin >> tmp;
	clearBuff();
	if (tmp == 1) {
		Stack<float> stack;
		float tmp_n;
		char menu = 't';
		while (menu != '0') {
			cout << "1. Add Element" << endl;
			cout << "3. show" << endl;
			cout << "0. Quit" << endl;

			cin >> menu;
			clearBuff();
			switch (menu) {
				case '1':
					system("clear");
					cout << "Enter val. of element: " << endl;
					cin >> tmp_n;
					clearBuff();
					stack.Push(tmp_n); ///< позволяет пользователю ввести элемент
					break;
				case '3':
					system("clear");
					stack.stkPrint();
					break;
				default:
					break;
			}
		}
		return 0;

	} else if (tmp == 2) {
		Stack<unsigned char> stack;
		unsigned int tmp_n;
		char menu = 'f';
		while (menu != '0') {
			cout << "1. Add Element" << endl;
			cout << "3. show" << endl;
			cout << "0. Quit" << endl;

			cin >> menu;
			clearBuff();
			switch (menu) {
				case '1':
					system("clear");
					cout << "Enter val. of element: " << endl;
					cin >> tmp_n;
					clearBuff();
					stack.Push((unsigned char) tmp_n); ///< позволяет пользователю ввести элемент
					break;
				case '3':
					system("clear");
					stack.stkPrint();
				default:
					break;
			}
		}
		return 0;
	} else
		throw invalid_argument("Не по ГОСТу");

}

template<class Tdata>
void deleteList(Stack<Tdata> *stack) {
	while (!stack->Empty())
		stack->Pop();
}
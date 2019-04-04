//
// Created by vhund on 24.03.2019.
//
#include "../Lib/Stack.h"
#include <iostream>

using namespace std;

void clearBuff() {       ///< @brief Чистит буфер
	cin.clear();           // Restore input stream to working state
	cin.ignore(100, '\n'); // Get rid of any garbage that user might have entered}
}

template<class Tdata>
void deleteList(Stack<Tdata> *stack);

template<class Tdata>
Tdata findMin(Stack<Tdata> stack) {
	Tdata min = numeric_limits<Tdata>::max();
	while (!stack.Empty()) {
		if (stack.showData() < min)
			min = stack.showData();
		stack.next();
	}
	return min;
}

template<class Tdata>
void norm(Stack<Tdata> *stack) {
	Tdata min = findMin(*stack);
	while (!stack->Empty()) {
		stack->setData(stack->showData() - min);
		stack->next();
	}
	stack->resetPstackToTop();
}

template<class Tdata>
void show(Stack<Tdata> stack) {
	while (!stack.Empty()) {
		cout << "--------" << endl
		     << +stack.showData() << endl
		     << "--------" << endl;
		stack.next();
	}
}

int main() {
	int tmp;
	cout << "Какой тип элементов массива? \n 1)float\n 2)unsigned char" << endl;
	cin >> tmp;
	clearBuff();
	if (tmp == 1) {
		Stack<float> stack;
		float tmp_n;
		char menu = '0';
		while (menu != '7') {
			cout << "1. Add Element" << endl;
			cout << "2. norm" << endl;
			cout << "3. show" << endl;
			cout << "7. Quit" << endl;

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
				case '2':
					system("clear");
					norm(&stack);
					break;
				case '3':
					system("clear");
					show(stack);
					break;
				default:
					break;
			}
		}
		deleteList(&stack);
		return 0;

	} else if (tmp == 2) {
		Stack<unsigned char> stack;
		unsigned int tmp_n;
		char menu = '0';
		while (menu != '7') {
			cout << "1. Add Element" << endl;
			cout << "2. norm" << endl;
			cout << "3. show" << endl;
			cout << "7. Quit" << endl;

			cin >> menu;
			clearBuff();
			switch (menu) {
				case '1':
					system("clear");
					cout << "Enter val. of element: " << endl;
					cin >> tmp_n;
					clearBuff();
					stack.Push((unsigned char)tmp_n); ///< позволяет пользователю ввести элемент
					break;
				case '2':
					system("clear");
					norm(&stack);
					break;
				case '3':
					system("clear");
					show(stack);
					break;
				default:
					break;
			}
		}
		deleteList(&stack);
		return 0;

	} else
		throw invalid_argument("Не по ГОСТу");

}

template<class Tdata>
void deleteList(Stack<Tdata> *stack) {
	while (!stack->Empty())
		stack->Pop();
}
//
// Created by vhund on 25.06.2019.
//

#include "../Lib/Stack.h"
#include <iostream>

using namespace std;

void clearBuff() {       ///< @brief Чистит буфер
	cin.clear();           // Restore input stream to working state
	cin.ignore(4276, '\n'); // Get rid of any garbage that user might have entered}
}

template<class Tdata>
void deleteList(Stack<Tdata> *stack) {
	while (!stack->Empty())
		stack->Pop();
}

template<class Tdata>
Stack<Tdata> stack;

template<class Tdata>
Tdata tmp;

int main() {
	int iElementType;
	cout << "Выберите тип элементов массива? \n 1)float\n 2)unsigned char" << endl;
	cin >> iElementType;
	clearBuff();
	while (iElementType != 1 and iElementType != 2) {
		cout << "Некорректный ввод, введите 1 или 2" << endl;
		cin >> iElementType;
		clearBuff();
	}
	char menu = 't';
	while (menu != '0') {
		cout << "1. Добавить элемент" << endl;
		cout << "2. Показать все элементы" << endl;
		cout << "0. Выход" << endl;

		cin >> menu;
		clearBuff();
		switch (menu) {
			case '1':
				system("clear");
				cout << "Enter val. of element: " << endl;
				if (iElementType == 1)
					cin >> tmp<float>;
				else
					scanf("%i", &tmp<unsigned char>);;
				clearBuff();

				if (iElementType == 1)
					stack<float>.Push(tmp<float>);
				else
					stack<unsigned char>.Push(tmp<unsigned char>);

				break;

			case '2':
				system("clear");
				cout << "\n_______\n";
				if (iElementType == 1)
					stack<float>.stkPrint();
				else
					stack<unsigned char>.stkPrint();
				break;

			default:
				break;
		}
	}
	if (iElementType == 1)
		deleteList(&stack<float>);
	else
		deleteList(&stack<unsigned char>);
	return 0;
}
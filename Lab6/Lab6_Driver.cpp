//
// Created by vhundef on 31.05.19.
//

#include <iostream>
#include "l_str.h"
#include "l_str_id.h"
#include "l_str_compl.h"

using namespace std;

void clearBuff() {       ///< @brief Чистит буфер
	cin.clear();           // Restore input stream to working state
	cin.ignore(4276, '\n'); // Get rid of any garbage that user might have entered}
}


void MainMenu();

int main() {
	MainMenu();
	return 0;
}

void arrayInitaliser(L_Str *arr[6], int arrSize) {
	int tmp;
	int i = 0;
	tmp = -1;
	bool flag = true;
	while (i < 6) {
		if (i >= arrSize) {
			arr[i] = nullptr;
		} else {
			cout << "Строка(1) Строка Идентификатор(2) или Комлексная строка(3)?" << endl;
			while (flag) {
				cin >> tmp;
				if (tmp == 1 || tmp == 2 || tmp == 3)
					flag = false;
				clearBuff();
			}
			char bufStr[32];
			std::cout << "Введите начальное значение: ";
			cin >> bufStr;
			if (tmp == 1) {
				arr[i] = new L_Str(bufStr);
				arr[i]->setType('s');
			} else if (tmp == 2) {
				arr[i] = new L_Str_ID(bufStr);
				arr[i]->setType('i');
			} else {
				arr[i] = new L_Str_Compl(bufStr);
				arr[i]->setType('c');
			}
			flag = true;
		}
		i++;
	}
}

void checkStr(L_Str *str) {
	int sel = 0;
	while (sel != 4) {
		cout << "1. Вывести строку" << endl;
		cout << "2. Вывести размер строки" << endl;
		cout << "3. Прегрузка равенства" << endl;
		cout << "4. Выйти в меню выбора элемента" << endl;
		cin >> sel;
		clearBuff();
		switch (sel) {
			case 1:
				str->Print();
				break;
			case 2:
				cout<<"Размер строки: "<<str->GetLength()<<endl;
				break;
			case 3:
				char bufStr[32];
				std::cout << "Введите новое значение для строки: ";
				cin>>bufStr;
				*str = bufStr;
				break;
		}
	}
}

void checkStr_ID(L_Str_ID *str) {
	int sel = 0;
	while (sel != 5) {
		cout << "1. Вывести строку" << endl;
		cout << "2. Вывести размер строки" << endl;
		cout << "3. Прегрузка равенства" << endl;
		cout << "4. Прегрузка вычитания" << endl;
		cout << "5. Выйти в меню выбора элемента" << endl;
		cin >> sel;
		clearBuff();
		switch (sel) {
			case 1:
				str->Print();
				break;
			case 2:
				cout<<"Размер строки: "<<str->GetLength()<<endl;
				break;
			case 3: {
				char bufStr[32];
				std::cout << "Введите новое значение для строки: ";
				cin>>bufStr;
				*str = bufStr;
				break;
			}
			case 4: {
				char bufStr[32];
				std::cout << "Введите значение которое надо вычесть из строки: ";
				cin>>bufStr;
				*str - bufStr;
				break;
			}
		}
	}
}

void checkStr_Coml(L_Str_Compl *str) {
	int sel = 0;
	while (sel != 6) {
		cout << "1. Вывести строку" << endl;
		cout << "2. Размер размер строки" << endl;
		cout << "3. Прегрузка равенства" << endl;
		cout << "4. Прегрузка вычитания" << endl;
		cout << "5. Прегрузка деления" << endl;
		cout << "6. Выйти в меню выбора элемента" << endl;
		cin >> sel;
		system("clear");
		system("cls");
		clearBuff();
		switch (sel) {
			case 1:
				str->Print();
				break;
			case 2:
				cout<<"Размер строки"<<str->GetLength()<<endl;
				break;
			case 3: {
				char bufStr[32];
				std::cout << "Введите новое значение для строки: ";
				cin>>bufStr;
				*str = bufStr;
				break;
			}
			case 4: {
				char bufStr[32];
				std::cout << "Введите значение которое надо вычесть из строки: ";
				cin>>bufStr;
				*str - bufStr;
				break;
			}
			case 5: {
				char bufStr[32];
				std::cout << "Введите комплексное число на которое надо поделить строку: ";
				cin>>bufStr;
				*str / bufStr;
				break;
			}
		}
	}
}

void testArray(L_Str *arr[6]) {
	int sel = -1;
	while (sel != 0) {
		cout << "Для выхода в главное меню введите (0)" << endl;
		cout << "Введите номер элемента:" << endl;
		cin >> sel;
		if (sel == 0) break;
		clearBuff();
		while (sel < 0 || sel >= 7 || arr[sel - 1] == nullptr) {
			cout << "Ошибка нет такого элемента" << endl;
			cin >> sel;
			clearBuff();
		}
		system("clear");
		system("cls");
		cout << "Вы выбрали элемент под номером:" << sel << endl;
		sel--;
		if (arr[sel]->getType() == 's')
			checkStr(arr[sel]);

		if (arr[sel]->getType() == 'i')
			checkStr_ID(dynamic_cast<L_Str_ID *>(arr[sel]));

		if (arr[sel]->getType() == 'c')
			checkStr_Coml(dynamic_cast<L_Str_Compl *>(arr[sel]));
	}
}

void MainMenu() {

	int cmd = -1;
	bool canTest = false;
	while (cmd != 3) {
		system("clear");
		system("cls");
		cout << "1. Инициализация" << endl;
		if (canTest)
			cout << "2. Тестирование" << endl;
		cout << "3. Выход" << endl;

		cout << endl << "Выберите пункт: ";
		cin >> cmd;
		clearBuff();
		system("clear");
		system("cls");
		L_Str *arr[6];
		switch (cmd) {
			case 1: {
				int tmp = 0;
				cout << "Введите кол-во элементов (от 4 до 6)" << endl;
				while (tmp < 4 || tmp > 6) {
					cin >> tmp;
					clearBuff();
				}
				arrayInitaliser(arr, tmp);
				system("clear");
				system("cls");
				canTest = true;
				break;
			}
			case 2:
				if (canTest)
					testArray(arr);
				break;
		}
	}

	std::cout << "Нажмите ENTER для выхода..." << std::endl;
	cin.get();

}


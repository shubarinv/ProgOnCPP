/*
 * Copyright (C) Vladimir Shubarin - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Written by Vladimir Shubarin <vhundef@gmail.com>, Mar 2019
 */
#include "Lab3_1.h"
#include <iostream>
#include <math.h>

using namespace std;

void clearBuff() {       ///< @brief Чистит буфер
	cin.clear();           // Restore input stream to working state
	cin.ignore(100, '\n'); // Get rid of any garbage that user might have entered}
}
double radtoDeg(double rad) {
	return (rad / M_PI) * 180;
}
int main() {
	char menu = '-';
	cout << "Задайте первый треугольник" << endl;

	triangle tr1;
	system("clear");
	cout << "Задайте второй треугольник" << endl;
	triangle tr2(12, 5, 90.0);
	while (menu != '0') {

		cout << "1. Найти стороны первого треугольника" << endl;
		cout << "2. Найти углы первого треугольника" << endl;
		cout << "3. Найти высоту первого треугольника" << endl;
		cout << "4. Найти стороны второго треугольника" << endl;
		cout << "5. Найти углы второго треугольника" << endl;
		cout << "6. Найти высоту второго треугольника" << endl;
		cout << "7. Сравнить на равенство" << endl;
		cout << "8. Сравнить на подобие" << endl;
		cout << "9. Copy" << endl;
		cout << "0. Quit" << endl;

		cin >> menu;
		clearBuff();
		switch (menu) {
			case '1':
				system("clear");
				cout << "------------" << endl;
				cout << "Side A= " << tr1.getSideA() << endl;
				cout << "Side B= " << tr1.getSideB() << endl;
				cout << "Side C= " << tr1.findSideC() << endl;
				cout << "------Lab3_1------" << endl;
				break;
			case '2':
				system("clear");
				cout << "------------" << endl;
				cout << "Angle A= " << radtoDeg(tr1.findAngleA()) << endl;
				cout << "Angle B= " << radtoDeg(tr1.getAngleB()) << endl;
				cout << "Angle C= " << radtoDeg(tr1.findAngleC()) << endl;
				cout << "------------" << endl;
				tr1.CheckAnglesCorrectnesss();
				break;
			case '3':
				system("clear");
				cout << "Высота " << tr1.findHeight() << endl;
				break;
			case '4':
				system("clear");
				cout << "------------" << endl;
				cout << "Side A= " << tr2.getSideA() << endl;
				cout << "Side B= " << tr2.getSideB() << endl;
				cout << "Side C= " << tr2.findSideC() << endl;
				cout << "------------" << endl;
				break;
			case '5':
				system("clear");
				cout << "------------" << endl;
				cout << "Angle A= " << radtoDeg(tr2.findAngleA()) << endl;
				cout << "Angle B= " << radtoDeg(tr2.getAngleB()) << endl;
				cout << "Angle C= " << radtoDeg(tr2.findAngleC()) << endl;
				cout << "------------" << endl;
				tr2.CheckAnglesCorrectnesss();
				break;
			case '6':
				system("clear");
				cout << "Высота " << tr2.findHeight() << endl;
				break;
			case '7':
				system("clear");
				bool tmp;
				tmp = tr1 == tr2;
				cout << "Equal" << tmp << endl;
				break;
			case '8':
				system("clear");
				tmp = tr1 ^ tr2;
				cout << "Alike" << tmp << endl;
				break;
			case '9':
				system("clear");
				triangle tr3 = tr1;
				cout << "----TR3------" << endl;
				cout << "------------" << endl;
				cout << "Side A= " << tr3.getSideA() << endl;
				cout << "Side B= " << tr3.getSideB() << endl;
				cout << "Side C= " << tr3.findSideC() << endl;
				cout << "------------" << endl;

				cout << "------------" << endl;
				cout << "Angle A= " << radtoDeg(tr3.findAngleA()) << endl;
				cout << "Angle B= " << radtoDeg(tr3.getAngleB()) << endl;
				cout << "Angle C= " << radtoDeg(tr3.findAngleC()) << endl;
				cout << "------------" << endl;
				tr3.CheckAnglesCorrectnesss();
				break;
		}
	}
	return 0;
}

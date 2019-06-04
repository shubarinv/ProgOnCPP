/*
 * Copyright (C) Vladimir Shubarin - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Written by Vladimir Shubarin <vhundef@gmail.com>, Mar 2019
 */
/*
 * Класс «Треугольник».
 * Поля: длины двух сторон и величина угла между ними.
 * Методы: вычисление длин всех сторон, высоты, проведенной из большего угла,
 * перегрузка операций «==» как сравнение на равенство и «^» как определение
 * подобия треугольников.
 */

#include "Lab3_1.h"
#include <cmath>
#include <iostream>

using namespace std;

double radToDeg(double rad) {
	return (rad / M_PI) * 180;
}

double triangle::findSideC() {
	sideC = sqrt(pow(sideB, 2) + pow(sideA, 2) - 2 * sideB * sideA * cos(angleB));
	if (sideA + sideB > sideC && sideA + sideC > sideB && sideB + sideC > sideA) {
		return sideC;
	} else
		throw logic_error("WAIT A MINUTE! That's ain't triangle!");
}

bool triangle::CheckAnglesCorrectness() {
	if ((((180 - (radToDeg(angleA) + radToDeg(angleB))) != radToDeg(angleC)) &&
	     ((180 - (radToDeg(angleA) + radToDeg(angleC))) != radToDeg(angleB))) ||
	    (radToDeg(angleA) + radToDeg(angleB) + radToDeg(angleC) < 179.9)) {
		throw logic_error("WOW, результат не правильный(Какая неожиданность)");
	}
	return true;
}
double triangle::findAngleA(){
	//cout<< endl << "----Функция нахождения угла A-----" << endl;
	angleA = acos((pow(sideA,2)+pow(sideC,2)-pow(sideB,2))/(2.*sideA*sideC));
	return angleA;
}
double triangle::findAngleC(){
//	cout<< endl << "----Функция нахождения угла C-----" << endl;
	angleC = acos((pow(sideC,2)+pow(sideB,2)-pow(sideA,2))/(2.*sideC*sideB));
	return angleC;
}

double triangle::findHeight() {
	//cout << endl<< "----Функция нахождения высоты-----" << endl;
	double p = 0.5 * (sideA + sideB + sideC);
	double divs = findMaxAngle();
	if (divs == angleA)
		divs = sideA;
	else if (divs == angleB)
		divs = sideB;
	else
		divs = sideC;
	double h = (2 * sqrt(p * (p - sideA) * (p - sideB) * (p - sideC))) / divs;
	return h;
}

bool triangle::operator==(triangle &tr) {
	tr.findSideC();
	tr.findAngleA();
	tr.findAngleC();
	tr.CheckAnglesCorrectness();
	if (sideC == tr.sideC && angleA == tr.angleA && sideA == tr.sideA)
		return true;
	else if (sideA == tr.sideA && angleB == tr.angleB && sideB == tr.sideB)
		return true;
	else if (sideB == tr.sideB && angleC == tr.angleC && sideC == tr.sideC)
		return true;
	else if (angleC == tr.angleC && sideA == tr.sideA && angleA == tr.angleA)
		return true;
	else if (angleA == tr.angleA && sideB == tr.sideB && angleB == tr.angleB)
		return true;
	else if (angleB == tr.angleB && sideC == tr.sideC && angleC == tr.angleC)
		return true;
	else
		return sideA == tr.sideA && sideB == tr.sideB && sideC == tr.sideC;
}

bool triangle::operator^(triangle &tr) {
	cout << "----Перегрузка оператора возведения в степень-----" << endl;
	tr.findSideC();
	tr.findAngleA();
	tr.findAngleC();
	tr.CheckAnglesCorrectness();

	if ((angleA == tr.angleA && angleB == tr.angleB) ||
	    (angleA == tr.angleA && angleC == tr.angleC) ||
	    (angleB == tr.angleB && angleC == tr.angleC))
		return true;
	else if ((sideC / tr.sideC == sideA / tr.sideA) && angleA == tr.angleA)
		return true;
	else if ((sideA / tr.sideA == sideB / tr.sideB) && angleB == tr.angleB)
		return true;
	else if ((sideB / tr.sideB == sideC / tr.sideC) && angleC == tr.angleC)
		return true;
	else
		return sideA / tr.sideA == sideB / tr.sideB == sideC / tr.sideC;
}

triangle::triangle() {
	double tmp;
	cout << "Введите длину стороны1: ";
	cin >> sideA;
	clearBuff();
	cout << endl << "Введите длину стороны2: ";
	cin >> sideB;
	clearBuff();
	cout << endl << "Введите угол: ";
	cin >> tmp;
	while (tmp >= 180) {
		cout << "Не по ГОСТу" << endl;
		cin >> tmp;
		clearBuff();
	}
	angleB = tmp;
	clearBuff();
	angleB = angleB * M_PI / 180;
}

triangle::triangle(double SideA, double SideB, double AngleB) {
	cout << "side1= " << SideA << endl
	     << "side2= " << SideB << endl
	     << "angle1= " << AngleB << endl;
	sideA = SideA;
	sideB = SideB;
	angleB = AngleB;
	angleB = angleB * M_PI / 180;
}

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

#ifndef PROGONCPP_LAB3_1_H
#define PROGONCPP_LAB3_1_H

#include <iostream>

class triangle {
public:
	double findHeight();

	bool operator==(triangle &tr);

	bool operator^(triangle &tr);

	triangle();

	triangle(double, double, double);

	double findSideC();


	void clearBuff() {       ///< @brief Чистит буфер
		std::cin.clear();           // Restore input stream to working state
		std::cin.ignore(100, '\n'); // Get rid of any garbage that user might have entered}
	}

	double findAngleA();

	double findAngleC();

	bool CheckAnglesCorrectnesss();

private:
	double sideA, sideB, sideC, angleA, angleB, angleC;
public:
	double getSideB() const {
		return sideB;
	}
	double getSideA() const {
		return sideA;
	}

	double getSideC() const {
		return sideC;
	}

	double getAngleA() const {
		return angleA;
	}

	double getAngleB() const {
		return angleB;
	}

	double getAngleC() const {
		return angleC;
	}

private:
	double findMaxAngle() {
		if (angleA > angleB && angleA > angleC)
			return angleA;
		if (angleB > angleA && angleB > angleC)
			return angleB;
		if (angleC > angleA && angleC > angleB)
			return angleC;
		else
			throw;
	}

};

#endif // PROGONCPP_LAB3_1_H

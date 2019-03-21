/*
 * Copyright (C) Vladimir Shubarin - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Written by Vladimir Shubarin <vhundef@gmail.com>, Mar 2019
 */
/*
 * Класс «Треугольник».
 * Поля: длины двух сторон и величина угла между ними.
 * Методы: вычисление длин всех сторон, высоты, проведенной из большего угла,
 * перегрузка операций «==» как сравнение на равенство и «^» как определение подобия треугольников.
 */

#include "Lab3_1.h"
#include <cmath>

double triangle::findAllSides() {
    sideC = sqrt(pow(sideB, 2) + pow(sideA, 2) - 2 * sideB * sideA * cos(angleA));
    return sideC;
}

double triangle::findHeight() {
    double p=1/2.f*(sideA*sideB*sideC);
    double h=(2*sqrt(p*(p-sideA)*(p-sideB)*(p-sideC)))/findMaxAngle();
    return h;
}

bool triangle::operator==(triangle &tr) {
    return false;
}

bool triangle::operator^(triangle &tr) {
    return false;
}


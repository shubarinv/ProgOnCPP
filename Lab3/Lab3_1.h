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

#ifndef PROGONCPP_LAB3_1_H
#define PROGONCPP_LAB3_1_H

class triangle {
public:
    double findHeight();
    bool operator==(triangle &tr);
    bool operator^(triangle &tr);
    triangle();
    triangle(double,double, double);
    void findAllAngles(double*, double*);
    void findSideC(double *);
    /*
    void findAllAngles();
    void findSideC();
     */
    double sideA, sideB, sideC, angleA, angleB, angleC;

private:
    double findMaxAngle(){
        if (angleA>angleB&&angleA>angleC)
            return angleA;
        if (angleB>angleA&&angleB>angleC)
            return angleB;
        if (angleC>angleA&&angleC>angleB)
            return angleC;
        else return angleA;
    }
};



#endif //PROGONCPP_LAB3_1_H

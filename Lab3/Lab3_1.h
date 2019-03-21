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
    void init();
    bool operator==(triangle &tr);
    bool operator^(triangle &tr);

private:
    double sideA, sideB, sideC, angleA, angleB, angleC;

    double findMaxAngle(){
        if (angleA>angleB&&angleA>angleC)
            return angleA;
        if (angleB>angleA&&angleB>angleC)
            return angleB;
        if (angleC>angleA&&angleC>angleB)
            return angleC;
        else return angleA;
    }

    void * findAllAngles(double*, double*);
    void findSideC(double *);
};



#endif //PROGONCPP_LAB3_1_H

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
#include <iostream>

using namespace std;


void triangle::findSideC(double * sideC) {
    *sideC = sqrt(pow(sideB, 2) + pow(sideA, 2) - 2 * sideB * sideA * cos(angleA));
    cout<<"------------"<<endl;
    cout<<"Side A= "<<sideA<<endl;
    cout<<"Side B= "<<sideB<<endl;
    cout<<"Side C= "<<*sideC<<endl;
    cout<<"------------"<<endl;
}

void * triangle::findAllAngles(double *angleB, double *angleC) {
    *angleB=(pow(sideA,2)-pow(sideC,2)+pow(sideB,2))/(2*sideA*sideB);
    *angleC=(pow(sideA,2)-pow(sideB,2)+pow(sideC,2))/(2*sideA*sideC);
    cout<<"------------"<<endl;
    cout<<"Angle A= "<<angleA<<endl;
    cout<<"Angle B= "<<*angleB<<endl;
    cout<<"Angle C= "<<*angleC<<endl;
    cout<<"------------"<<endl;

}
double triangle::findHeight() {
    double p=0.5*(sideA+sideB+sideC);
    double divs=findMaxAngle();
    if(divs==angleA)
        divs=sideA;
    else if(divs==angleB)
        divs=sideB;
    else
        divs=sideC;
    double h=(2*sqrt(p*(p-sideA)*(p-sideB)*(p-sideC)))/divs;
    return h;
}

bool triangle::operator==(triangle &tr) {
    tr.findAllAngles(&tr.angleB,&tr.angleC);
    tr.findSideC(&tr.sideC);
    if (sideC==tr.sideC&&angleA==tr.angleA&&sideA==tr.sideA)
        return true;
    else if (sideA==tr.sideA&&angleB==tr.angleB&&sideB==tr.sideB)
        return true;
    else if (sideB==tr.sideB&&angleC==tr.angleC&&sideC==tr.sideC)
        return true;
    else if (angleC==tr.angleC&&sideA==tr.sideA&&angleA==tr.angleA)
        return true;
    else if (angleA==tr.angleA&&sideB==tr.sideB&&angleB==tr.angleB)
        return true;
    else if (angleB==tr.angleB&&sideC==tr.sideC&&angleC==tr.angleC)
        return true;
    else return sideA == tr.sideA && sideB == tr.sideB && sideC == tr.sideC;
}

bool triangle::operator^(triangle &tr) {
    if((angleA==tr.angleA&&angleB==tr.angleB)||(angleA==tr.angleA&&angleC==tr.angleC)||(angleB==tr.angleB&&angleC==tr.angleC))
        return true;
    else if((sideC/tr.sideC==sideA/tr.sideA)&&angleA==tr.angleA)
        return true;
    else if((sideA/tr.sideA==sideB/tr.sideB)&&angleB==tr.angleB)
        return true;
    else if((sideB/tr.sideB==sideC/tr.sideC)&&angleC==tr.angleC)
        return true;
    else return sideA / tr.sideA == sideB / tr.sideB == sideC / tr.sideC;
}

void triangle::init(){
    cout<<"Ввдите длинну стороны1: ";
    cin>>sideA;
    cout<<endl<<"Ввдите длинну стороны2: ";
    cin>>sideB;
    cout<<endl<<"Ввдите угол: ";
    cin>>angleA;
    angleA=angleA*M_PI/180;
    findSideC(&sideC);
    findAllAngles(&angleB,&angleC);
}


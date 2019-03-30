/*
 * Copyright (C) Vladimir Shubarin - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Written by Vladimir Shubarin <vhundef@gmail.com>, Mar 2019
 */
#include "Lab3_1.h"
#include <iostream>

using namespace std;

void clearBuff() {       ///< @brief Чистит буфер
  cin.clear();           // Restore input stream to working state
  cin.ignore(100, '\n'); // Get rid of any garbage that user might have entered}
}

int main() {
  char menu = '-';
  cout << "Задайте первый треугольник" << endl;

  triangle tr1;
  system("clear");
  cout << "Задайте второй треугольник" << endl;
  triangle tr2(3.0, 4, 30.0);
  while (menu != '9') {

    cout << "1. Найти стороны первого треугольника" << endl;
    cout << "2. Найти углы первого треугольника" << endl;
    cout << "3. Найти высоту первого треугольника" << endl;
    cout << "4. Найти стороны второго треугольника" << endl;
    cout << "5. Найти углы второго треугольника" << endl;
    cout << "6. Найти высоту второго треугольника" << endl;
    cout << "7. Сравнить на равенство" << endl;
    cout << "8. Сравнить на подобие" << endl;
    cout << "9. Выйти" << endl;

    cin >> menu;
    clearBuff();
    switch (menu) {
    case '1':
      system("clear");
      tr1.findSideC(&tr1.sideC);
      break;
    case '2':
      system("clear");
      tr1.findAllAngles(&tr1.angleA, &tr1.angleC);
      break;
    case '3':
      system("clear");
      cout << "Высота " << tr1.findHeight() << endl;
      break;
    case '4':
      system("clear");
      tr2.findSideC(&tr2.sideC);
      break;
    case '5':
      system("clear");
      tr2.findAllAngles(&tr2.angleA, &tr2.angleC);
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
      tr3.findSideC(&tr3.sideC);
      tr3.findAllAngles(&tr3.angleA, &tr3.angleC);
      break;
    }
  }
  return 0;
}

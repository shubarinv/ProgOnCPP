//
// Created by vhundef on 23.03.19.
//
#include <limits>
/*
 * Типы аргументов float и unsigned char.
 * 1. Нормирование элементов массива вычитанием из каждого из них минимального элемента этого массива.
 * 2. АТД Стек. Структура хранения – связанный список.
 */

using namespace std;

template<class Tdata>
Tdata findMin(Tdata arr[],int len){
    Tdata min=numeric_limits<Tdata>::max();
    for (int i = 0; i < len; ++i) {
    if (arr[i]<min)
        min=arr[i];
    }
}

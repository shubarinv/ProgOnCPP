/*
 * Copyright (C) Vladimir Shubarin - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Written by Vladimir Shubarin <vhundef@gmail.com>, Mar 2019
 */
#include <iostream>
#include "Lab3_1.h"

using namespace std;

int main(){
    triangle tr;
    tr.init();
    cout << "Height: "<<tr.findHeight();

    cout<<"Второй треугольник"<<endl;
    triangle tr2;
    tr2.init();
    bool tmp=tr==tr2;
    cout<<"equal? "<<tmp<<endl;
    tmp=tr^tr2;
    cout<<"alike? "<<tmp<<endl;
    return 0;
}

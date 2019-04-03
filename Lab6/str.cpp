//
// Created by vhund on 27.03.2019.
//

#include "str.h"
#include <iostream>
str::~str() { cout << "----Destructor from str.cpp was called----" << endl; }
str::str() { cout << "----Constructor from str.cpp was called----" << endl; }
str &str::operator=(const str &str2) {
  cout << "----override of '=' from str.cpp was called----" << endl;
}
str::str(char *) {
  cout << "----Init w/ Cstring from str.cpp was called----" << endl;
}
str::str(str &obj) {
  cout << "----Copy class from str.cpp was called----" << endl;
}

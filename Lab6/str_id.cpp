//
// Created by vhund on 30.03.2019.
//

#include "str_id.h"
#include <iostream>

strID::~strID() {
  cout << "----Destructor from str_id.cpp was called----" << endl;
}
strID &strID::operator=(const strID &str2) {
  cout << "----override of '=' from str_id.cpp was called----" << endl;
}
strID::strID() {
  cout << "----Constructor from str_id.cpp was called----" << endl;
}
strID::strID(strID &obj) {
  cout << "----Copy class from str_id.cpp was called----" << endl;
}
strID::strID(char *) {
  cout << "----Init w/ Cstring from str_id.cpp was called----" << endl;
}

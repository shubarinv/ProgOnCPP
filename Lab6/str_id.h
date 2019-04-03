//
// Created by vhund on 30.03.2019.
//

#ifndef PROGONCPP_STR_ID_H
#define PROGONCPP_STR_ID_H

#include "str.h"
class strID: public str {
public:
  strID();
  strID(char *);
  strID(strID &obj);
  ~strID();
  strID &operator=(const strID &str2);
};

#endif // PROGONCPP_STR_ID_H

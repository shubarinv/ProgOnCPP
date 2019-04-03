//
// Created by vhund on 27.03.2019.
//

#ifndef PROGONCPP_STR_H
#define PROGONCPP_STR_H

#include <cstring>
using namespace std;

class str {
private:
  char *allocatedmemory{allocatedmemory = nullptr};
  int strlength{strlength = 0};

public:
  str();
  str(char *);
  str(str &obj);
  ~str();
  str &operator=(const str &str2);
};

#endif // PROGONCPP_STR_H

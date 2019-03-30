//
// Created by vhund on 27.03.2019.
//

#ifndef PROGONCPP_STR_H
#define PROGONCPP_STR_H

#include <cstring>
using namespace std;

class str {
private:
    char *allocatedmemory;
    int strlength;
public:
    str();
    str(String);

};


#endif //PROGONCPP_STR_H

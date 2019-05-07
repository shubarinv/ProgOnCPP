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
	int strSizeBytes;
public:
	int getStrSizeBytes() const;

	void setStrSizeBytes(int strSizeBytes);

public:
	char *getAllocatedmemory() const;

	int getStrlength() const;


public:
	str();

	str(char);

	str(char *);

	str(str &obj);

	~str();

	str &operator=(const str &str2);
};

#endif // PROGONCPP_STR_H

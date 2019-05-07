//
// Created by vhund on 27.03.2019.
//

#include "str.h"
#include <iostream>

int copyCalls = 0;

str::~str() { cout << "----Destructor from str.cpp was called----" << endl; }

str::str() { cout << "----Constructor from str.cpp was called----" << endl; }

str &str::operator=(const str &str2) {
	cout << "----override of '=' from str.cpp was called----" << endl;
}

str::str(char *cstring) {
	cout << "----Init w/ Cstring from str.cpp was called----" << endl;
	allocatedmemory = cstring;
}

str::str(str &obj) {
	cout << "----Copy call from str.cpp was called----" << endl;
	cout << "This call number is: " << copyCalls << endl;

}

char *str::getAllocatedmemory() const {
	return allocatedmemory;
}

int str::getStrlength() const {
	return strlength;
}

str::str(char chr) {
	cout << "----Init call from str.cpp with char was called----" << endl;
	allocatedmemory = new char;
	allocatedmemory = &chr;
}

int str::getStrSizeBytes() const {
	return strSizeBytes;
}

void str::setStrSizeBytes(int strSize) {
	str::strSizeBytes = strSize;
}

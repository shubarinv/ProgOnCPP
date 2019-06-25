//
// Created by vhundef on 31.05.19.
//

#ifndef PROGONCPP_L_STR_COMPL_H
#define PROGONCPP_L_STR_COMPL_H


#include <iostream>
#include "l_str.h"

using namespace std;

class L_Str_Compl : public L_Str {
public:
	L_Str_Compl();

	virtual ~L_Str_Compl();

	L_Str_Compl(const char *str);

	L_Str_Compl(const L_Str_Compl &other);

	L_Str_Compl &operator=(const L_Str_Compl &other);

	L_Str_Compl operator/(const L_Str_Compl &other) const;

	L_Str_Compl operator-(const L_Str_Compl &other) const;

private:
	void check();

	int ToString();

	int FromString();

	double m_re;
	double m_im;
};

L_Str_Compl::L_Str_Compl() : L_Str() {
	std::cout << "L_Str_Compl()" << std::endl;
	check();
}

L_Str_Compl::~L_Str_Compl() {
	std::cout << "~L_Str_Compl()" << std::endl;
}

L_Str_Compl::L_Str_Compl(const char *str) : L_Str(str) {
	std::cout << "L_Str_Compl(const char* str)" << std::endl;
	check();
}

L_Str_Compl::L_Str_Compl(const L_Str_Compl &other)
		: L_Str(other) {
	static size_t numCall = 0;
	std::cout << "L_Str_Compl(const L_Str_Compl& otherStr)" << ++numCall << std::endl;

	check();
}

L_Str_Compl &L_Str_Compl::operator=(const L_Str_Compl &other) {
	std::cout << "operator=(const L_Str_Compl& otherStr)" << std::endl;

	Assign(other);
	m_re = other.m_re;
	m_im = other.m_im;

	check();

	return *this;
}

void L_Str_Compl::check() {
	std::cout << "Check()" << std::endl;

	bool correctStr = FromString() == 0;

	if (!correctStr)
		Clear();
}


int L_Str_Compl::ToString() {
	std::cout << "ToString()" << std::endl;

	char bufStr[32];

	if (sprintf(bufStr, "%.2lfi%.2lf", m_re, m_im) != 0) {
		*static_cast<L_Str *>(this) = L_Str(bufStr);
		return 0;
	} else
		return 1;
}

int L_Str_Compl::FromString() {
	std::cout << "FromString()" << std::endl;

	if (m_str == nullptr)
		return 2;

	if (sscanf(m_str, "%lfi%lf", &m_re, &m_im) == 2)
		return 0;
	else
		return 1;
}

L_Str_Compl L_Str_Compl::operator/(const L_Str_Compl &other) const {
	std::cout << "operator/(const L_Str_Compl& other)" << std::endl;

	L_Str_Compl res;

	if (other.m_re != 0 && other.m_im != 0) {
		double a = other.m_re * other.m_re + other.m_im * other.m_im;
		res.m_re = (m_re * other.m_re + m_im * other.m_im) / a;
		res.m_im = (m_im * other.m_re - m_re * other.m_im) / a;

		res.ToString();
	}

	return res;
}

L_Str_Compl L_Str_Compl::operator-(const L_Str_Compl &other) const {
	std::cout << "operator-()" << std::endl;

	L_Str_Compl res;

	if (other.m_re != 0 && other.m_im != 0) {
		res.m_re = m_re - other.m_re;
		res.m_im = m_im - other.m_im;

		res.ToString();
	}

	return res;
}

#endif //PROGONCPP_L_STR_COMPL_H

//
// Created by vhundef on 31.05.19.
//

#ifndef PROGONCPP_L_STR_ID_H
#define PROGONCPP_L_STR_ID_H


#include "l_str.h"

class L_Str_ID : L_Str{
public:
	L_Str_ID();
	~L_Str_ID();
	L_Str_ID(const char* str);
	L_Str_ID(L_Str_ID& otherStr);
	L_Str_ID&operator=(const L_Str_ID& otherStr);
	L_Str_ID&operator-(const L_Str_ID& otherStr);

private:
	void checkStr();
	void ToLower();


};

L_Str_ID::L_Str_ID(): L_Str() {
	std::cout << "L_Str_ID()" << std::endl;
	checkStr();
}

// ����������
L_Str_ID::~L_Str_ID() {
	std::cout << "~L_Str_ID()" << std::endl;
}

// �����������, ����������� ��-������
L_Str_ID::L_Str_ID(const char *str)
		: L_Str(str) {
	std::cout << "L_Str_ID(const char* str)" << std::endl;
	checkStr();
}

// ����������� �����������
L_Str_ID::L_Str_ID(L_Str_ID &otherStr): L_Str(otherStr) {
	static size_t numCall = 0;
	std::cout << "L_Str_ID(const L_Str_ID& otherStr)" << ++numCall << std::endl;

	checkStr();
}

// ���������� ��������� ������������
L_Str_ID &L_Str_ID::operator=(const L_Str_ID &otherStr) {
	std::cout << "operator=(const L_Str_ID& otherStr)" << std::endl;

	Assign(otherStr);
	checkStr();

	return *this;
}

// �������� ������ �� ������������ �������� ���������� ���������������
void L_Str_ID::checkStr() {
	std::cout << "CheckStr()" << std::endl;

	bool correctStr = GetLength() > 0;

	// ������ �������� ����� ���� ������ ����� ��� ���� �������������
	// ���� ������������� ������� �� ����� �����, �� ��� �� ������ ���� ���� �������������
	correctStr = correctStr && ((GetLength() > 1 && m_str[0] == '_') || isalpha(m_str[0]));

	// ���������� ��������� ������ ���� ���� �������������, ����� ��� �����
	for (size_t i = 1; correctStr && i < GetLength(); ++i)
		correctStr = correctStr && (m_str[i] == '_' || isalnum(m_str[i]));

	// ���� ������ ����������, �� ������� �� ��������
	if (!correctStr)
		Clear();
}

// ������� �������� � ������� �������
void L_Str_ID::ToLower() {
	std::cout << "ToLower()" << std::endl;

	for (size_t i = 0; i < GetLength(); ++i)
		if (isalpha(m_str[i]))
			m_str[i] = tolower(m_str[i]);
}

//  �������� ���������
L_Str_ID& L_Str_ID::operator-(const L_Str_ID &otherStr) {
	std::cout << "operator-(const L_Str_ID& otherStr)" << std::endl;

	// ������������ ������� ������
	if (m_str == nullptr || otherStr.m_str == nullptr) {
		L_Str_ID res1("Nope");
		return res1;
	}
	//�������� �� ������� ������� �������� � ����������� ���������
	char *b = otherStr.m_str, *p;
	int l = 0;

	for (p = m_str; *p != '\0'; ++p)
		if (strchr(otherStr.m_str, *p) == nullptr)
			b[l++] = *p;

	b[l] = '\0';
	L_Str_ID res2(b);

	delete[] b;

	return res2;
}

#endif //PROGONCPP_L_STR_ID_H

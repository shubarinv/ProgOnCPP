//
// Created by vhundef on 31.05.19.
//

#ifndef PROGONCPP_L_STR_H
#define PROGONCPP_L_STR_H


#include <glob.h>
#include <iostream>
#include <cstring>

using namespace std;

class L_Str {
public:


	L_Str();


	virtual ~L_Str();


	L_Str(const char *str);


	L_Str(char c);


	L_Str(const L_Str &otherStr);


	L_Str &operator=(const L_Str &otherStr);


	size_t GetLength() const { return m_length; }


	void Print() const;


	virtual bool Initialized() const { return (m_str != nullptr); }

protected:


	void Clear();


	void Assign(const L_Str &otherStr);

protected:

	char *m_str;

	size_t m_length;

	size_t m_cap;

};

L_Str::L_Str() : m_cap(0), m_length(0), m_str(nullptr) {
	cout << "L_str()" << endl;
}

L_Str::~L_Str() {
	cout << "~L_str()" << endl;

	Clear();
}

void L_Str::Clear() {
	cout << "Clear()" << endl;
	delete[] m_str;
	m_str = nullptr;
	m_length = m_cap = 0;
}

L_Str::L_Str(const char *str) : m_str(nullptr), m_length(0), m_cap(0) {
	std::cout << "String(const char* str)" << std::endl;

	if (str == nullptr)
		return;

	m_length = strlen(str);
	m_cap = m_length + 1; // ���������� ����� ������� ������

	// ��������� ������ ��� ������
	m_str = new char[m_cap];

	// ����������� �������� ������ � ���������� ������
	if (m_str != nullptr)
		strcpy(m_str, str);
	else {
		// �� ������� �������� ������ - ����� ������
		m_str = nullptr;
		m_length = m_cap = 0;
	}
}

L_Str::L_Str(char c) : m_str(nullptr), m_length(1), m_cap(2) {
	std::cout << "String(char c)" << std::endl;

// ��������� ������ ��� ������
	m_str = new char[m_cap];

// ����������� �������� � ���������� ������
	if (m_str != nullptr) {
		m_str[0] = c;
		m_str[1] = '\0';
	} else {
// �� ������� �������� ������ - ����� ������
		m_str = nullptr;
		m_length = m_cap = 0;
	}
}

L_Str::L_Str(const L_Str &otherStr) : m_str(nullptr), m_length(otherStr.m_length), m_cap(otherStr.m_cap) {
	static size_t numCall = 0;
	std::cout << "String(const String& otherStr) " << ++numCall << std::endl;

	if (otherStr.m_str == nullptr) // �������� ���������� ������ �� ����������� �������
		return;

	// ��������� ������ ��� ������
	m_str = new char[m_cap];

	// ����������� �������� ������ � ���������� ������
	if (m_str != nullptr)
		strcpy(m_str, otherStr.m_str);
	else {
		// �� ������� �������� ������ - ����� ������
		m_str = nullptr;
		m_length = m_cap = 0;
	}
}
void L_Str::Assign(const L_Str& otherStr){
	std::cout << "Assign(const String& otherStr)" << std::endl;

	if (otherStr.m_str != nullptr) // �������� ���������� ������ �� �������������� �������
	{
		m_length = otherStr.m_length;

		// ���� ������ �� ���� ������� ����� ��� �� �� ���������� ��� ����� ������, �� �������� ����� ������
		if (m_str == nullptr || m_cap < otherStr.m_cap)
		{
			// ������� ������ ��������
			Clear();

			// ���������� �������� ������� ���������� ������
			m_cap = otherStr.m_cap;

			// ��������� ������ ��� ������
			m_str = new char [m_cap];
		}

		// ����������� �������� ������ � ���������� ������
		if (m_str != nullptr)
			strcpy(m_str, otherStr.m_str);
		else
		{
			// �� ������� �������� ������ - ����� ������
			m_str = nullptr;
			m_length = m_cap = 0;
		}
	}
	else
	{
		m_str = nullptr;
		m_length = otherStr.m_length;
		m_cap = otherStr.m_cap;
	}
}
L_Str& L_Str::operator=(const L_Str& otherStr)
{
	std::cout << "operator=(const String& otherStr)" << std::endl;

	Assign(otherStr);
	return *this;
}

// ������ ������ (����� �����������, ���������� ���� �������������� ���)
void L_Str::Print() const
{
	if (m_str == nullptr)
		std::cout << "Empty string" << std::endl;
	else
		std::cout << m_str << std::endl;
}

#endif //PROGONCPP_L_STR_H

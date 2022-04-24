#pragma once
#include <iostream>
#include <string>

using std::string;
using std::to_string;
using std::cout;

void append_with_zeros(int*, int);
int* convert_to_binary(int, int);

class Numeral_2 {
	friend void append_with_zeros(int*, int);
	friend int* convert_to_binary(int, int);

private:
	int* m_binary;
	int m_bits = 8;

public:
	Numeral_2() {}

	Numeral_2(int number) {
		m_binary = new int[m_bits];
		int mod, index = 7;

		while (number != 0) {
			mod = number % 10;
			number = number / 10;
			m_binary[index--] = mod;
		}
		append_with_zeros(m_binary, index);
	}
	
	Numeral_2(int number, int base) {
		if (base == 10) {
			m_binary = convert_to_binary(number, m_bits);
		}
	}

	//Конструктор копіювання
	Numeral_2(const Numeral_2& other) {
		m_bits = other.m_bits;
		m_binary = new int[m_bits];
		for (int i = 0; i < m_bits; i++) {
			m_binary[i] = other.m_binary[i];
		}
	}

	//Конструктор перенесення
	Numeral_2(Numeral_2&& other) {
		m_bits = other.m_bits;
		m_binary = other.m_binary;
		other.m_binary = nullptr;
		//nullptr присвоєно лише для other, далі деструктор видаляє other об'єкт і його адресу на nullptr
		//this->m_binary продовжує існувати з новою адресою від other.m_binary
	}

	~Numeral_2() { delete[] m_binary; }

	void print();
	int get_decimal();

	Numeral_2& operator = (const Numeral_2&);

	Numeral_2 operator + (const Numeral_2&);
};
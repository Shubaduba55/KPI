#pragma once
#include <iostream>
#include <string>

using std::string;
using std::to_string;
using std::cout;

void append_with_zeros(int*, int);
int* convert_to_binary(int, int, bool&);
void sign(int*, bool&, int&);


class Numeral_2 {
	friend void append_with_zeros(int*, int);
	friend int* convert_to_binary(int, int, bool&);
	friend void sign(int*, bool&, int&);
	friend int* add(const Numeral_2&, const Numeral_2&);
private:
	int* m_binary = nullptr;
	bool m_is_negative = 0;
	static const int m_bits;
	bool m_is_inverted = 0;
public:
	Numeral_2() {}
	//Numeral_2 one(54, 10);
	Numeral_2(int number) {
		m_binary = new int[m_bits];
		sign(m_binary, m_is_negative, number);
		int mod, index = m_bits - 1;
		while (number != 0) {
			mod = number % 10;
			number = number / 10;
			m_binary[index--] = mod;
		}
		append_with_zeros(m_binary, index);
		
	}
	
	Numeral_2(int number, int base) {
		if (base == 10) {
			m_binary = convert_to_binary(number, m_bits, m_is_negative);
		}
		else {
			m_binary = nullptr;
		}
	}

	//Конструктор копіювання
	Numeral_2(const Numeral_2& other) {
		m_binary = new int[m_bits];
		m_is_inverted = other.m_is_inverted;
		m_is_negative = other.m_is_negative;
		for (int i = 0; i < m_bits; i++) {
			m_binary[i] = other.m_binary[i];
		}
	}

	//Конструктор перенесення
	Numeral_2(Numeral_2&& other) {
		m_is_inverted = other.m_is_inverted;
		m_is_negative = other.m_is_negative;
		m_binary = other.m_binary;
		other.m_binary = nullptr;
		//nullptr присвоєно лише для other, далі деструктор видаляє other об'єкт і його адресу на nullptr
		//this->m_binary продовжує існувати з новою адресою від other.m_binary
	}

	~Numeral_2() { delete[] m_binary; }

	void print();

	string get_number();

	int get_decimal();

	void inversion();

	bool operator == (const Numeral_2&);

	bool operator >= (const Numeral_2&);

	Numeral_2 operator = (const Numeral_2&);

	Numeral_2 operator + (Numeral_2);

	Numeral_2& operator += (const int);

	Numeral_2& operator += (const Numeral_2&);

	Numeral_2 operator ++ ();

	Numeral_2 operator ++ (int);
};
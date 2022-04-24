#include "Class.h"

void append_with_zeros(int* binary, int start) {
	while (start >= 0) {
		binary[start--] = 0;
	}
}

int* convert_to_binary(int number, int bits) {
	int* binary = new int[bits];
	int index, mod;
	
	for (index = bits - 1; number >= 2; index--) {
		mod = number % 2;
		number = number / 2;
		binary[index] = mod;
	}
	binary[index--] = number;
	append_with_zeros(binary, index);

	return binary;
}

void Numeral_2::print() {
	string binary = "";
	for (int i = 0; i < m_bits; i++) {
		binary += to_string(m_binary[i]);
		if ((i + 1) % 4 == 0) { binary += " "; }

	}
	cout << binary;
}

int Numeral_2::get_decimal() {
	int number = 0;
	for (int i = 0; i < m_bits; i++) {
		number += pow(2, m_bits - i - 1) * m_binary[i];
	}
	return number; 
}

Numeral_2& Numeral_2::operator = (const Numeral_2& other) {
	if (this != nullptr) {
		delete[] m_binary;
	}
	
	m_bits = other.m_bits;
	m_binary = new int[m_bits];
	for (int i = 0; i < m_bits; i++) {
		m_binary[i] = other.m_binary[i];
	}
	return *this;
}
//111
//101
//1100
Numeral_2 Numeral_2::operator + (const Numeral_2& other) {
	int* binary = new int[m_bits];
	int increase = 0, temp_add;
	for (int i = m_bits - 1; i >= 0; i--) {
		temp_add = m_binary[i] + other.m_binary[i] + increase;
		switch (temp_add){
		case 0: 
			binary[i] = 0;
			increase = 0;
			break;

		case 1:
			binary[i] = 1;
			increase = 0;
			break;
		case 2:
			binary[i] = 0;
			increase = 1;
			break;
		case 3:
			binary[i] = 1;
			increase = 1;
			break;
		}
	}
	Numeral_2 temp;
	temp.m_bits = m_bits;
	temp.m_binary = binary;
	binary = nullptr;
	return temp;
}
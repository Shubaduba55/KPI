#include "Class.h"


void append_with_zeros(int* binary, int start) {
	//Функція для заповнення залишку масиву нулями
	while (start >= 1) {
		binary[start--] = 0;
	}
}

int* convert_to_binary(int number, int bits, bool& is_negative) {
	//перевід десяткового числа в двійкове через ділення на 2
	int* binary = new int[bits];
	sign(binary, is_negative, number);
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

void sign(int* binary, bool& is_negative, int& number) {
	//визначення знаку двійкового числа та встановлення "1" або "0" в перший біт
	if (number >= 0) {
		binary[0] = 0;
		is_negative = false;
	}
	else {
		binary[0] = 1;
		number *= -1;
		is_negative = true;
	}
	return;
}

int* add(const Numeral_2& current, const Numeral_2& other){
	//звичайне додавання двох двійкових чисел у стовпчик
	int* binary = new int[current.m_bits];
	int temp_add, increase = 0;
	for (int i = current.m_bits - 1; i >= 0; i--) {
		temp_add = current.m_binary[i] + other.m_binary[i] + increase;
		switch (temp_add) {
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
	return binary;
}

void Numeral_2::print() {
	//виведення двійкового числа з проміжком у 4 біти
	string binary = "";
	for (int i = 0; i < m_bits; i++) {
		binary += to_string(m_binary[i]);
		if ((i + 1) % 4 == 0) { binary += " "; }

	}
	cout << binary + "\n";
}

string Numeral_2::get_number() {
	string binary = "";
	for (int i = 0; i < m_bits; i++) {
		binary += to_string(m_binary[i]);
		if ((i + 1) % 4 == 0) { binary += " "; }

	}
	return binary;
}

int Numeral_2::get_decimal() {
	//перевід двійкового числа у десяткове
	int number = 0;
	for (int i = 1; i < m_bits; i++) {
		number += pow(2, m_bits - i - 1) * m_binary[i];
	}
	if (m_binary[0] == 1) { number = number * (-1); }
	return number; 
}

void Numeral_2::inversion() {
	//інверсія усіх бітів двійкового числа, окрім першого
	if (m_is_negative) {
		for (int i = 1; i < m_bits; i++) {
			(m_binary[i] == 1) ? m_binary[i] = 0 : m_binary[i] = 1;
		}
		this->m_is_inverted = !this->m_is_inverted;
		m_binary = add(*this, 1);
	}
}

bool Numeral_2::operator == (const Numeral_2& other) {
	//оператор перевірки рівності чисел
	bool check = true;
	for (int i = 0; i < m_bits && check; i++) {
		if (m_binary[i] != other.m_binary[i]) {
			check = false;
		}
	}
	return check;
}

Numeral_2 Numeral_2::operator = (const Numeral_2& other) {
	//оператор присвоєння
	if (this != nullptr) {
		delete[] m_binary;
	}
	
	//m_bits = other.m_bits;
	m_binary = new int[m_bits];
	m_is_inverted = other.m_is_inverted;
	m_is_negative = other.m_is_negative;
	for (int i = 0; i < m_bits; i++) {
		m_binary[i] = other.m_binary[i];
	}
	return *this;
}

Numeral_2 Numeral_2::operator + (Numeral_2 other) {
	//оператор додавання
	int current_decimal = this->get_decimal(),
		other_decimal = other.get_decimal();
	
	this->inversion();
	other.inversion();
	
	Numeral_2 temp;
	temp.m_binary = add(*this, other);
	temp.m_is_negative = temp.m_binary[0];
	
	if ((current_decimal + other_decimal) < 0) {
		temp.m_is_inverted = true;
	}
	else {
		temp.m_is_inverted = false;
	}

	temp.inversion();
	this->inversion();
	other.inversion();
	return temp;
}

Numeral_2& Numeral_2::operator += (const int number) {
	//оператор збільшення числа на вказане десяткове число
	Numeral_2 temp(number, 10);
	*this = *this + temp;
	return *this;
}

Numeral_2& Numeral_2::operator += (const Numeral_2& other) {
	//оператор збільшення числа на двійкове число
	*this = *this + other;
	return *this;
}

Numeral_2 Numeral_2::operator ++ () {
	//префіксний інкремент числа
	*this += 1;
	return *this;
}

Numeral_2 Numeral_2::operator ++ (int num) {
	//постфіксний інкремент числа
	Numeral_2 temp = *this;
	*this += 1;
	return temp;
}

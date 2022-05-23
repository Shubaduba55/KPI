#include "Class.h"
#include <Windows.h>
#include <random>

using std::cout;
using std::to_string;

int const Numeral_2:: m_bits = 8;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int increase = 2;
	Numeral_2 N1(-1000);
	Numeral_2 N2(-10, 10);
	Numeral_2 N3;
	cout << "Numbers info: N1 = " << N1.get_decimal() << "; N2 = " << N2.get_decimal() << "\n\n";
 
	++N1;
	cout << "++N1 = " << N1.get_decimal() << "\n";

	N2 += increase;
	cout << "N2 += "<< increase <<" :" << N2.get_decimal() << "\n";

	N3 = N1 + N2;

	cout << "N1 + N2 = " << N3.get_decimal();
 
	return 0;
}
/*
void errors_check(int);

Numeral_2* ascii_to_binary(string, int&);

string binary_to_ascii(Numeral_2*, int);
void errors_check(int numbers) {
	srand(time(NULL));
	int num_1, num_2, num_3;
	bool check = true;
	for (int i = 0; i < numbers && check; i++) {
		num_1 = rand() % 2000001 - 1000000;
		num_2 = rand() % 2000001 - 1000000;
		Numeral_2 one(num_1, 10); 
		Numeral_2 two(num_2, 10); 
		Numeral_2 three = one + two;
		num_3 = three.get_decimal();
		cout << "\n" + to_string(i + 1) + "." << to_string(num_1) + " + " + to_string(num_2) + " = " + to_string(num_3) + "\n" +
			"  " + one.get_number() + " + " + two.get_number() + " = " + three.get_number();
		
		if ((num_1 + num_2) != num_3) {
			check = false;
		}
	}
}

Numeral_2* ascii_to_binary(string word, int& length) {
	length = word.length();
	
	Numeral_2* arr = new Numeral_2[word.length()];
	string full_code = "";
	int code, count = 0;
	for (int i = 0; word[i] != '\0'; i++) {
		code = (int)word[i];
		Numeral_2 code_binary(code, 10);
		full_code += code_binary.get_number() + "|";
		arr[count++] = code_binary;
	}
	cout << full_code;
	return arr;
}

string binary_to_ascii(Numeral_2* arr, int length) {
	string tmp = "";
	for (int i = 0; i < length; i++) {
		tmp += (char)arr[i].get_decimal();
	}
	return tmp;
}

errors_check(100);
	int length;
	Numeral_2* arr = ascii_to_binary("Мама приготувала смачні сирники", length);
	string tmp = binary_to_ascii(arr, length);
	cout << "\n" << tmp;
	//Numeral_2 mob_phone(933938862, 10);
	//mob_phone.print();
	//cout << mob_phone.get_decimal();*/

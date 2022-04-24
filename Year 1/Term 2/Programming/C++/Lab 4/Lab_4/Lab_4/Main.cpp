#include "Class.h"
#include <Windows.h>

using std::cout;
using std::to_string;


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Numeral_2 one(1000, 10);
	Numeral_2 two(1, 10);
	Numeral_2 three;
	three = one + two;
	three.print();
	cout << "\n" << three.get_decimal();
	return 0;
}


//157

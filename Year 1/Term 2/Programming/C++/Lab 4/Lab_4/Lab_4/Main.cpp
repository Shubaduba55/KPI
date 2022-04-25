#include "Class.h"
#include <Windows.h>

using std::cout;
using std::to_string;


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Numeral_2 one(1, 10);
	Numeral_2 two(2, 10);
	
	one += 5;
	one.print();
	return 0;
}


//157

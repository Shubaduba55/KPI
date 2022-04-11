#include <Windows.h>
#include <iostream>
#include "createtxt.h"
#include "readtxt.h"
#include "countwinter.h"
#include "lastcentury.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	create_txt("File.txt");
	read_txt("File.txt");
	cout<< "\nКількість творів, написаних узимку: " << count_winter("File.txt") << "\n";
	last_century("File.txt", "Last century.txt");
	read_txt("Last century.txt");
	return 0;
}
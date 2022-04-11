#include "readtxt.h"

void read_txt(string name) {
	ifstream file_read;
	file_read.open(name, ios::binary);
	
	if (!file_read.is_open()) {
		cout << "\n__________Файл " << name << " не вдалося відкрити для читання__________\n";
	}
	else {
		cout << "\n__________Файл " << name << " відкрито для читання__________\n";
		Book temp;
		while (file_read.read((char*)&temp, sizeof(Book))) {
			cout << "\nНазва книги: "<< temp.name << "\nДата написання книги: "<< temp.date << "\nРік видання книги: "<< temp.year << "\n\n";
		}
		cout << "\n__________Файл " << name << " закрито__________\n";
	}

	file_read.close();
}
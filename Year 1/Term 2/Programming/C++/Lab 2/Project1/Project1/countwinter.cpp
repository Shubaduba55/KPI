#include "countwinter.h"

int count_winter(string name) {
	int count = 0;
	ifstream file_read;
	file_read.open(name, ios::binary);

	if (!file_read.is_open()) {
		cout << "\n__________Файл " << name << " не вдалося відкрити для підрахунку творів, написаних узимку__________\n";
	}
	else {
		cout << "\n__________Файл " << name << " відкрито для підрахунку творів, написаних узимку__________\n";
		Book temp;
		while (file_read.read((char*)&temp, sizeof(Book))) {
			string date = temp.date;
			date = date.substr(3, 2);
			if (date == "12" || date == "01" || date == "02") {
				count++;
			}
		}

		cout << "\n__________Файл " << name << " закрито__________\n";
	}

	file_read.close();
	return count;
}

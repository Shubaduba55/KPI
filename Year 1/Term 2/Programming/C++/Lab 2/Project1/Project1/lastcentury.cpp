#include "lastcentury.h"

void last_century(string name_read, string name_write) {
	
	ifstream file_read;
	ofstream file_write;
	file_read.open(name_read, ios::binary);
	file_write.open(name_write, ios::binary);
	
	if (!file_read.is_open() && !file_write.is_open()){
		cout << "\n__________Файли " << name_read << " та " << name_write << " не вдалося відкрити для підрахунку творів, виданих минулого століття__________\n";
	}
	else {
		cout << "\n__________Файли " << name_read << " та " << name_write << " відкрито для підрахунку творів, виданих минулого століття__________\n";
		Book temp;
		
		while (file_read.read((char*)&temp, sizeof(Book))) {
			string year = temp.year;
			year = year.substr(0, 2);
			if (year == "19") {
				file_write.write((char*)&temp, sizeof(Book));
			}
		}

		cout << "\n__________Файли " << name_read << " та " << name_write << " закрито__________\n";
	}

	file_read.close();
	file_write.close();
	return;
}

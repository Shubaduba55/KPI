#include "readtxt.h"

void read_txt(string name) {
	ifstream file_read;
	file_read.open(name, ios::binary);
	
	if (!file_read.is_open()) {
		cout << "\n__________���� " << name << " �� ������� ������� ��� �������__________\n";
	}
	else {
		cout << "\n__________���� " << name << " ������� ��� �������__________\n";
		Book temp;
		while (file_read.read((char*)&temp, sizeof(Book))) {
			cout << "\n����� �����: "<< temp.name << "\n���� ��������� �����: "<< temp.date << "\nг� ������� �����: "<< temp.year << "\n\n";
		}
		cout << "\n__________���� " << name << " �������__________\n";
	}

	file_read.close();
}
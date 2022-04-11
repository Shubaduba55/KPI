#include "countwinter.h"

int count_winter(string name) {
	int count = 0;
	ifstream file_read;
	file_read.open(name, ios::binary);

	if (!file_read.is_open()) {
		cout << "\n__________���� " << name << " �� ������� ������� ��� ��������� �����, ��������� ������__________\n";
	}
	else {
		cout << "\n__________���� " << name << " ������� ��� ��������� �����, ��������� ������__________\n";
		Book temp;
		while (file_read.read((char*)&temp, sizeof(Book))) {
			string date = temp.date;
			date = date.substr(3, 2);
			if (date == "12" || date == "01" || date == "02") {
				count++;
			}
		}

		cout << "\n__________���� " << name << " �������__________\n";
	}

	file_read.close();
	return count;
}

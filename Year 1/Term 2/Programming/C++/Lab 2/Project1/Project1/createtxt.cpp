#include "createtxt.h"

void insert(string line, char* name) {
	for (int i = 0; line[i] != '\0'; i++) {
		name[i] = line[i];
	}
	name[line.length()] = '\0';
	return;
}

void create_txt(string name) {
	ofstream file_write;
	string answer;
	
	
	cout << "�������� ���� Main.txt?(���/�) ";
	cin >> answer;
	
	(answer == "���") ? file_write.open(name, ios::binary | ios::trunc) : file_write.open(name, ios::binary | ios::app);
	//file_write.open(name, ios::binary);
	if (!file_write.is_open()) {
		cout << "\n__________���� " << name << " �� ������� ������� ��� ������__________\n";
	}
	else {
		cout << "\n__________���� " << name << " ������� ��� ������__________\n";
		
		int num;
		cout << "������ ������� ���� ��� ������: ";
		cin >> num; 

		Book* arr = new Book[num];
		string line;

		for (int i = 0; i < num; i++) {
			cin.ignore();
			cout << "������ ��'� �����: ";
			getline(cin, line);
			insert(line, arr[i].name);
			cout << "������ ���� ��������� �����(00.00): ";
			cin >> arr[i].date;
			cout << "������ �� ������� �����(1111): ";
			cin >> arr[i].year; cout << "\n\n";
			file_write.write((char*)&arr[i], sizeof(Book));
		}

		delete[] arr;
		cout << "__________���� " << name << " �������__________\n";
	}

	file_write.close();
}
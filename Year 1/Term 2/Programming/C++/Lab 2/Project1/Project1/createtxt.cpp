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
	
	
	cout << "ќчистити файл Main.txt?(так/н≥) ";
	cin >> answer;
	
	(answer == "так") ? file_write.open(name, ios::binary | ios::trunc) : file_write.open(name, ios::binary | ios::app);
	//file_write.open(name, ios::binary);
	if (!file_write.is_open()) {
		cout << "\n__________‘айл " << name << " не вдалос€ в≥дкрити дл€ запису__________\n";
	}
	else {
		cout << "\n__________‘айл " << name << " в≥дкрито дл€ запису__________\n";
		
		int num;
		cout << "¬каж≥ть к≥льк≥сть книг дл€ запису: ";
		cin >> num; 

		Book* arr = new Book[num];
		string line;

		for (int i = 0; i < num; i++) {
			cin.ignore();
			cout << "¬каж≥ть ≥м'€ книги: ";
			getline(cin, line);
			insert(line, arr[i].name);
			cout << "¬каж≥ть дату написанн€ книги(00.00): ";
			cin >> arr[i].date;
			cout << "¬каж≥ть р≥к виданн€ книги(1111): ";
			cin >> arr[i].year; cout << "\n\n";
			file_write.write((char*)&arr[i], sizeof(Book));
		}

		delete[] arr;
		cout << "__________‘айл " << name << " закрито__________\n";
	}

	file_write.close();
}
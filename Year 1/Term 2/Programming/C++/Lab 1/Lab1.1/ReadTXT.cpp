#include "ReadTXT.h"

void ReadTXT(string name) {
	//Відкриття файлу для читання
	ifstream fromfile;
	fromfile.open(name);
	string line;
	//Перевірка відкриття файлу
	if (!fromfile.is_open()) {
		cout << "\n\nФайл: " << name << " не вдалося відкрити" << endl;
	}
	else {
		cout << "\n\n__________Читання файлу "<< name <<"__________\n" << endl;
		//Вивід вмісту файлу в консоль
		while (!fromfile.eof()) {
			line = "";
			getline(fromfile, line);
			cout << line <<endl;
		}
		cout << "\n__________Завершення читання файлу__________\n\n" << endl;
	}
	//Закриття файлу
	fromfile.close();
}


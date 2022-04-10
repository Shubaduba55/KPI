#include "CreateMainTXT2.h"


void CreateMainTXT2() {
	//Відкриття файлу
	ofstream outmain;
	string answer;
	cout << "Очистити файл Main.txt?(так/ні) ";
	cin >> answer;
	(answer == "так") ? outmain.open("Main.txt", ios::trunc) : outmain.open("Main.txt", ios::app);
	cin.ignore();
	//Перевірка відкриття файлу
	if (!outmain.is_open()) {
		cout << "Помилка відкриття файлу" << endl;
	}
	else {
		cout << "__________Файл відкрито__________" << endl;
		//Отримання тексту до моменту вводу комбінації клавіш Сtrl+S
		string line;
		getline(cin, line, char(19));
		//Видалення відступів \n
		while (line[line.length()-1] == '\n') {
			line.pop_back();
		}
			
		outmain << line;

		cout << "Завершення воду, Ctrl+S отримано\n __________Файл закрито__________" << endl;
	}
	//Закриття файлу
	outmain.close();
}


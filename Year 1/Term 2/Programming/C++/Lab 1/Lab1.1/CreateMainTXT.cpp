#include "CreateMainTXT.h"

void CreateMainTXT() {
	
	ofstream outmain;
	outmain.open("Main.txt");
	if (!outmain.is_open()) {
		cout << "Помилка відкриття файлу"<< endl;
	}
	else {
		cout << "__________Файл відкрито__________" << endl;
		RegisterHotKey(NULL, 1, MOD_CONTROL, 0x0D);
		MSG msg = {};
		string line;
		while (!PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			cout << "Введіть слова в рядок: ";
			getline(cin, line);
			outmain << line << "\n";
		}
		
		
		cout << "Завершення воду, Ctrl+Enter отримано\n __________Файл закрито__________" << endl;
		
		UnregisterHotKey(NULL, 1);
		
	}
	outmain.close();
}
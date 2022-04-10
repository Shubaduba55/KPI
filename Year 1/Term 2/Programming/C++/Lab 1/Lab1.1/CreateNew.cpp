#include "CreateNew.h"

void CreateNew(string name1, string name2) {
	ifstream Main;
	ofstream NewFile1;
	ofstream NewFile2;
	Main.open("Main.txt");
	NewFile1.open(name1);
	NewFile2.open(name2);
	
	if (!NewFile1.is_open() && !NewFile2.is_open() && !Main.is_open() ) {
		cout << "Помилка відкриття файлу" << endl;
	}
	else {
		cout << "__________Файли відкрито__________\n" << endl;
		string line;
		
	
		for (int count = 1; !Main.eof(); count++) {
			getline(Main, line);

			
			if (count % 2 == 0) {
				NewFile1 << line <<"\n";
			}
			else {
				NewFile2 << line << "\n";
			}
		}

		cout << "\n__________Файли закрито__________" << endl;
	}

	NewFile1.close();
	NewFile2.close();
	Main.close();
}
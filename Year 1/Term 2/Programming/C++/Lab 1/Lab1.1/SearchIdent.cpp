#include "SearchIdent.h"

void Search(string main, string name) {
	
	ifstream Main;
	ofstream ID;
	Main.open(main);
	ID.open(name);

	if (!Main.is_open() && !ID.is_open()) {
		cout << "Файли: "<< main <<" та "<< name <<" не вдалося відкрити" << endl;
	}
	else {
		cout <<"Файли: "<< main<<" та "<< name <<" відкрито " << endl;
		/*Створення змінних:
		text:запис вмісту файлу
		id:запис ідентифікатора
		start:точка, з якої починаємо пошук символу '='
		i:лічильник для зворотнього руху
		*/
		vector<string> library; 
		bool check;
		string text, id = "";
		int start =	0, i;
		
		//Отримання даних з файлу, поки не він не закінчиться
		getline(Main, text, '\26');
		start = text.find('=', start);
		
		/*
		Пошук символу '=' та виділення ідентифікатора
		Якщо символ не знайдено, то .find() повертає значення -1
		*/
		while (start!=-1) {
			//Перевірка, чи не натрапили на комбінацію '=='
			if (text[start + 1] == '=') {
				start = text.find('=', start + 2);
			} 
			else {
				i = start;
				//Переміщення на кінець ідентифікатора
				while (text[--i] == ' ') {} 
				//Зчитування ідентифікатора
				while (isalpha(text[i]) || isdigit(text[i] ) ) {
					id += text[i];
					i--;
				}
				//Переворот ідентифікатора задом наперед, адже ми його зчитували саме так
				reverse(id.begin(), id.end());
				if (id!="") {
					check = true;
					for (int j = 0; j < library.size() ; j++) {
						if (library[j] == id) { check = false; };
					}
					if (check) {
						ID << id << '\n';
						library.push_back(id);
					}
					
				}
								
				id = "";
				start = text.find('=', start + 1);
			}
			
		}
		cout << " Файли: " << main << " та " << name << " закрито " << endl;
	}
	
	Main.close();
	ID.close();
}


#include "addlinesarray.h"

void add_lines_array(Text* arr, int len) {
	/*cout << "Уведіть номери текстів, які хочете модифікувати, через кому" << endl;
	string numbers;
	getline(cin, numbers);*/
	string answer, temp;
	cin.ignore();
	for (int i = 0; i < len; i++) {
		cout << "\nХочете змінити текст "<< i+1 << " (так/ні): ";
		getline(cin, answer);
		if (answer == "так") {
			cout << "\nУведіть текст(для зупинки Ctrl+S): " << endl;
			
			getline(cin, temp, char(19));
			arr[i].add_line(temp);
			temp = "";
			cin.ignore();
		}
	}
	return;
}
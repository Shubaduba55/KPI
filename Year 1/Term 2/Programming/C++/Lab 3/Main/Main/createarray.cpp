#include "createarray.h"

Text* create_array(int& len) {
	cout << "Уведіть довжину масиву текстів: ";
	cin >> len; cin.ignore();
	Text* arr = new Text[len];
	string text;
	for (int i = 0; i < len; i++) {
		cout << "\nУведіть текст(для зупинки Ctrl+S): " << endl;
		cin.ignore();
		getline(cin, text, char(19));
		arr[i].add_line(text);
		text = "";
	}
	return arr;
}
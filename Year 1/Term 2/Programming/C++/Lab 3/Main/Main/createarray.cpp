#include "createarray.h"

Text* create_array(int& len) {
	cout << "������ ������� ������ ������: ";
	cin >> len; cin.ignore();
	Text* arr = new Text[len];
	string text;
	for (int i = 0; i < len; i++) {
		cout << "\n������ �����(��� ������� Ctrl+S): " << endl;
		cin.ignore();
		getline(cin, text, char(19));
		arr[i].add_line(text);
		text = "";
	}
	return arr;
}
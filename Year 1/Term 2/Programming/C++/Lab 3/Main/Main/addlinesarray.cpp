#include "addlinesarray.h"

void add_lines_array(Text* arr, int len) {
	/*cout << "������ ������ ������, �� ������ ������������, ����� ����" << endl;
	string numbers;
	getline(cin, numbers);*/
	string answer, temp;
	cin.ignore();
	for (int i = 0; i < len; i++) {
		cout << "\n������ ������ ����� "<< i+1 << " (���/�): ";
		getline(cin, answer);
		if (answer == "���") {
			cout << "\n������ �����(��� ������� Ctrl+S): " << endl;
			
			getline(cin, temp, char(19));
			arr[i].add_line(temp);
			temp = "";
			cin.ignore();
		}
	}
	return;
}
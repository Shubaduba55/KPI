#include "printarray.h"

void print_array(Text* arr, int len) {
	for (int i = 0; i < len; i++) {
		cout << "\n����� �� ������� " << i + 1 << ": " << endl;
		arr[i].print();
	}
	return;
}
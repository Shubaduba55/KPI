#include "maxduplicate.h"

int max_duplicate(Text* arr, int len) {
	int max = arr[0].find_duplicates(), id = 0, max_check, same_check = 0;
	
	for (int i = 1; i < len; i++) {
		max_check = arr[i].find_duplicates();
		if (max < max_check) {
			max = max_check;
			id = i;
		}
		else if (max == max_check) {
			same_check++;
		}
	}
	if (same_check == len - 1) {
		cout << "\n� ��� ������ �������� ������� ��������� ���� (" << max << ")\n";
	}
	else {
		cout << "\n����� � ��������� ������� ��������� ������� (" << max << ") �� �����: " << id + 1 <<
			"\n³� ������� ���:\n";
		arr[id].print();
	}
	return id;
}
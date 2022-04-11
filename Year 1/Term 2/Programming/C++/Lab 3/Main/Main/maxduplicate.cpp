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
		cout << "\nУ всіх текстів однакова кількість подвоєнних літер (" << max << ")\n";
	}
	else {
		cout << "\nТекст з найбільшою кількістю подвоєнних символів (" << max << ") має номер: " << id + 1 <<
			"\nВін виглядає так:\n";
		arr[id].print();
	}
	return id;
}
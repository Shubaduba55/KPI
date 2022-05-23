#include "Functions.h"

void fill_arr(int number, Figure* figures) {
	for (int i = 0; i < number; i++) {
		figures[i].set_points();
	}
}
Figure* create_arr(int& number) {
	int angles;
	cout << "”вед≥ть к≥льк≥сть кут≥в у ф≥гур: ";
	cin >> angles;
	cout << "\n”вед≥ть к≥льк≥сть ф≥гур: ";
	cin >> number;
	Figure* arr = nullptr;
	if (angles == 5) {
		arr = new Pentagon[number];
	}
	else if (angles == 6) {
		arr = new Hexagon[number];
	}
	fill_arr(number, arr);
	return arr;
}

int max_perimeter(int number, Figure* figures) {
	int id = 0;
	float max_perimeter = figures[0].get_perimeter();
	float perimeter;
	for (int i = 0; i < number; i++) {
		perimeter = figures[i].get_perimeter();
		if (max_perimeter < perimeter) {
			max_perimeter = perimeter;
			id = i;
		}
	}
	return id;
}
int min_square(int number, Figure* figures) {
	int id = 0;
	float min_square = figures[0].get_square();
	float square;
	for (int i = 1; i < number; i++) {
		square = figures[i].get_square();
		if (min_square > square) {
			min_square = square;
			id = i;
		}
	}
	return id;
}

void print_arr(int number, Figure* arr) {
	for (int i = 0; i < number; i++) {
		cout << i + 1 << ". " << arr[i].get_number() << "-кутник [ " << arr[i].get_perimeter() << "//" << arr[i].get_square() << " ] " <<
			arr[i] << "\n";
	}
}
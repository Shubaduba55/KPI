#include <Windows.h>
#include "Functions.h"
#include "Figure.h"


//Point points[6]{Point(0, 0), Point(0, 2), Point(1, 3), Point(2, 2), Point(2, 0), Point(1, -1)};
//Point points[6]{Point(0, 0), Point(0, 2), Point(2, 2), Point(2, 0), Point(1, -1)};
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int one, two;
	Figure* arr1 = create_arr(one);
	Figure* arr2 = create_arr(two);
	
	int max_per = max_perimeter(one, arr1);
	int min_sq = min_square(two, arr2);

	cout << arr1[max_per].get_number() << "-кутник з максимальним периметром " << arr1[max_per].get_perimeter() << "(" << arr1[max_per].get_square()
		<<"): " << arr1[max_per] << "\n";
	cout << arr2[min_sq].get_number() << "-кутник з мінімальною площею " << arr2[min_sq].get_square() << "(" << arr2[min_sq].get_perimeter()
		<< "): " << arr2[min_sq] << "\n";
	
	print_arr(one, arr1);
	print_arr(two, arr2);
	delete[] arr1, arr2;

	return 0;
}


#include <Windows.h>
#include "Class.h"
#include "createarray.h"
#include "printarray.h"
#include "addlinesarray.h"
#include "maxduplicate.h"


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "____________________________________________________________\n";
	
	int len;
	Text* arr = create_array(len);
	
	cout << "____________________________________________________________\n";
	
	print_array(arr, len);
	
	cout << "____________________________________________________________\n";
	
	add_lines_array(arr, len);
	
	cout << "____________________________________________________________\n";
	
	int id = max_duplicate(arr, len);
	
	cout << "____________________________________________________________\n";
	delete[] arr;
	return 0;
}
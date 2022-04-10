#include "CreateMainTXT2.h"
#include "ReadTXT.h"
#include "SearchIdent.h"
#include "Windows.h"


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	CreateMainTXT2();
	ReadTXT("Main.txt");
	Search("Main.txt", "ID.txt");
	ReadTXT("ID.txt");

	return 0;
}


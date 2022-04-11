#include "Class.h"

void Text::print() { cout << this->text << endl; return;  }

void Text::add_line(string line) { 
	(text != "") ? this->text += "\n" + line : this->text = line;
	return; }

int Text::find_duplicates() {
	int count = 0;
	for (int i = 1; text[i] != '\0'; i++) {
		if (text[i - 1] == text[i] && text[i] != '\n') { count++; }
	}
	return count;
}
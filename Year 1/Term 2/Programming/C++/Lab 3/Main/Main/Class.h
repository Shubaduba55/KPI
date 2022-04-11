#pragma once
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;


class Text {
private:
	string text;
public:
	Text() {};
	Text(string line) : text(line)
	{};
	~Text() {};
	
	void print();
	void add_line(string);
	int find_duplicates();
};
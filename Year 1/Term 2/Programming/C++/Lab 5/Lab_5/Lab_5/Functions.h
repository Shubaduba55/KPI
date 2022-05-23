#pragma once
#include "Point.h"
#include "Figure.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include <iostream>

using std::cout;
using std::cin;

Figure* create_arr(int&);
int max_perimeter(int, Figure*);
int min_square(int, Figure*);
void print_arr(int, Figure*);
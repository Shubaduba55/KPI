#include "Pentagon.h"

Pentagon::Pentagon() : Figure() { set_number(5); }
Pentagon::Pentagon(const Point* points): Figure(5, points) {}
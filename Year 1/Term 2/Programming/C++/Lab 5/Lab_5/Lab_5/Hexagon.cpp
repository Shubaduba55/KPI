#include "Hexagon.h"

Hexagon::Hexagon() : Figure() { set_number(6); }
Hexagon::Hexagon(const Point* points) : Figure(6, points) {}
#pragma once
#include <iostream>
#include "Point.h"

using std::cout;
using std::cin;

float calc_sq_triangle(const Point&, const Point&, const Point& = Point(0, 0));
Point calc_avg(int, Point*);

class Figure {
	friend Point;
private:
	float calc_perimeter();
	float calc_square();
protected:
	int m_number;
	Point* m_points;
	float m_perimeter;
	float m_square;

public:
	Figure();
	Figure(int, const Point*);
	Figure(const Figure&);
	Figure(Figure&&);
	~Figure();

	void set_points();
	int get_number();
	float get_perimeter();
	float get_square();
	void set_number(int);
	friend ostream& operator <<(ostream&, Figure);
};

/*class Triangle : public Figure {
private:
	int const m_number = 3;
	Point m_points[3];
public:
	Triangle(const Point*);
	Triangle(const Figure&);
	float calc_square();
};*/
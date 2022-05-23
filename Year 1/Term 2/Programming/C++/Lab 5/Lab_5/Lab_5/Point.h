#pragma once
#include "iostream"
#include <math.h>
using std::cout;
using std::ostream;

class Point {
private:
	float m_x, m_y;
public:
	Point();
	Point(float, float);
	Point(const Point&);//конструктор копіювання
	~Point() {}
	void set_x(float);
	void set_y(float);
	void set(float, float);
	int get_x() const;
	int get_y() const;
	Point operator+(const Point&);
	void operator+=(const Point&);
	void operator/=(const int);
	friend ostream& operator <<(ostream&, const Point&);
	friend float calc_distance(const Point&, const Point&);
};
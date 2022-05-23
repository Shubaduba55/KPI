#include "Point.h"

//constructors:
Point::Point(): m_x(0), m_y(0){}
Point::Point(float x, float y) : m_x(x), m_y(y) {}
Point::Point(const Point& other): m_x(other.m_x), m_y(other.m_y){}

//methods:
void Point::set(float x, float y) { m_x = x; m_y = y; }
void Point::set_x(float x) { m_x = x;}
void Point::set_y(float y) { m_y = y; }
int Point::get_x() const { return m_x; }
int Point::get_y() const { return m_y; }

//operators:
Point Point::operator+(const Point& other) {
	Point tmp;
	tmp.m_x = m_x + other.m_x;
	tmp.m_y = m_y + other.m_y;
	return tmp;
}
void Point::operator+=(const Point& other){
	m_x += other.m_x;
	m_y += other.m_y;
}
void Point::operator/=(const int number) {
	m_x /= number;
	m_y /= number;
}
//friend functions
ostream& operator <<(ostream& out, const Point& point) {
	out << "(" << point.m_x << "; " << point.m_y << ")";
	return out;
}
float calc_distance(const Point& point_a, const Point& point_b) {
	float x = pow(point_a.m_x - point_b.m_x, 2);
	float y = pow(point_a.m_y - point_b.m_y, 2);
	return sqrt(x+y);
}
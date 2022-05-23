#include "Figure.h"


//constructors:
Figure::Figure() : m_number(0), m_points(nullptr), m_perimeter(0), m_square(0) {};
Figure::Figure(int number, const Point* points) {
	m_number = number;
	m_points = new Point[m_number];
	for (int i = 0; i < m_number; i++) {
		m_points[i] = points[i];
	}
	m_perimeter = 0;
	m_square = 0;
}
Figure::Figure(const Figure& other) {
	m_number = other.m_number;
	m_points = new Point[m_number];
	for (int i = 0; i < m_number; i++) {
		m_points[i] = other.m_points[i];
	}
	m_perimeter = other.m_perimeter;
	m_square = other.m_perimeter;
}
Figure::Figure(Figure&& other) {
	m_number = other.m_number;
	m_points = other.m_points;
	other.m_points = nullptr;
	m_perimeter = other.m_perimeter;
	m_square = other.m_perimeter;
}
Figure::~Figure() {
	delete[] m_points;
}

//methods:
void Figure::set_points(){
	float x, y;
	for (int i = 0; i < m_number; i++) {
		cout << "Уведіть координати точки " << i + 1 << ": \nx: ";
		cin >> x;
		cout << "y: ";
		cin >> y; 
		m_points[i].set(x, y);
	}
}
float Figure::calc_perimeter() {
	for (int i = 0; i < m_number - 1; i++) {
		m_perimeter += calc_distance(m_points[i], m_points[i + 1]);
	}
	if (m_number > 2) {
		m_perimeter += calc_distance(m_points[m_number - 1], m_points[0]);
	}
	return m_perimeter;
}
float Figure::calc_square() {
	if (m_number == 3) {
		m_square = calc_sq_triangle(m_points[0], m_points[1], m_points[2]);
	}
	else if(m_number >= 4) {
		Point avg = calc_avg(m_number, m_points);
		for (int i = 0; i < m_number - 1; i++) {
			m_square += calc_sq_triangle(m_points[i], m_points[i + 1], avg);
		}
		m_square += calc_sq_triangle(m_points[m_number - 1], m_points[0], avg);
	}
	return m_square;
}
float Figure::get_perimeter() {
	if (m_number >= 2 && m_perimeter == 0) {
		calc_perimeter();
	}
	return m_perimeter;
}
float Figure::get_square() {
	if (m_number >= 3 && m_square == 0) {
		calc_square();
	}
	return m_square;
}
int Figure::get_number() { return m_number; }
void Figure::set_number(int num) {
	m_number = num; 
	delete[] m_points;
	m_points = new Point[m_number];
}


//friend functions:
ostream& operator <<(ostream& out, Figure figure) {
	for (int i = 0; i < figure.m_number; i++) {
		out << figure.m_points[i] << " ";
	}
	return out;
}


//help functions:
float calc_sq_triangle(const Point& point_a, const Point& point_b, const Point& point_c) {
	float side_a = calc_distance(point_a, point_b);
	float side_b = calc_distance(point_b, point_c);
	float side_c = calc_distance(point_c, point_a);
	float semi_p = (side_a + side_b + side_c) / 2;
	return sqrt(semi_p * (semi_p - side_a) * (semi_p - side_b) * (semi_p - side_c));
}
Point calc_avg(int number, Point* points) {
	Point avg;
	for (int i = 0; i < number; i++) { avg += points[i]; }
	avg /= number;
	return avg;
}

//Triangle::
/*Triangle::Triangle(const Point* points) {
	for (int i = 0; i < 3; i++) {
		m_points[i] = points[i];
	}
	m_perimeter = 0;
	m_square = 0;
}
float Triangle::calc_square() {
	m_square = calc_sq_triangle(m_points[0], m_points[1], m_points[2]);
	return m_square;
}*/
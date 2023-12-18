#include "triangle.h"
#include <cmath>
#include <stdexcept>

Triangle::Triangle(const Point& a, const Point& b, const Point& c) : a(a), b(b), c(c) {
	double area = std::abs(0.5 * (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)));
	if (area == 0) {
		throw std::invalid_argument("Vertices of the triangle are collinear");
	}
}

double Triangle::getArea() const {
	double ab = std::sqrt(std::pow(b.x - a.x, 2) + std::pow(b.y - a.y, 2));
	double bc = std::sqrt(std::pow(c.x - b.x, 2) + std::pow(c.y - b.y, 2));
	double ca = std::sqrt(std::pow(a.x - c.x, 2) + std::pow(a.y - c.y, 2));
	double s = (ab + bc + ca) / 2.0;
	return std::sqrt(s * (s - ab) * (s - bc) * (s - ca));
}

void Triangle::scale(double factor) {
	Point center = getCenter();
	a.x = center.x + (a.x - center.x) * factor;
	a.y = center.y + (a.y - center.y) * factor;
	b.x = center.x + (b.x - center.x) * factor;
	b.y = center.y + (b.y - center.y) * factor;
	c.x = center.x + (c.x - center.x) * factor;
	c.y = center.y + (c.y - center.y) * factor;
}

Point Triangle::getCenter() const {
	return Point((a.x + b.x + c.x) / 3.0, (a.y + b.y + c.y) / 3.0);
}

std::string Triangle::getName() const {
	return "Triangle";
}

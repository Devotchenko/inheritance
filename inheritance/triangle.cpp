#include "triangle.h"
#include <cmath>

Triangle::Triangle(const Point& a, const Point& b, const Point& c) : a(a), b(b), c(c) {}

double Triangle::getArea() const {
    return std::abs(0.5 * (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)));
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
    return Point((a.x + b.x + c.x) / 3, (a.y + b.y + c.y) / 3);
}

std::string Triangle::getName() const {
    return "TRIANGLE";
}

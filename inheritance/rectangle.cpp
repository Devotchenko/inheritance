#include "rectangle.h"
#include <cmath>
#include <stdexcept>

Rectangle::Rectangle(const Point& topLeft, const Point& bottomRight)
	: topLeft(topLeft), bottomRight(bottomRight) {
	if (topLeft.x >= bottomRight.x || topLeft.y >= bottomRight.y) {
		throw std::invalid_argument("Invalid coordinates for the corners of the rectangle");
	}
}

double Rectangle::getArea() const {
	return std::abs((bottomRight.x - topLeft.x) * (topLeft.y - bottomRight.y));
}

void Rectangle::scale(double factor) {
	Point center = getCenter();
	topLeft.x = center.x + (topLeft.x - center.x) * factor;
	topLeft.y = center.y + (topLeft.y - center.y) * factor;
	bottomRight.x = center.x + (bottomRight.x - center.x) * factor;
	bottomRight.y = center.y + (bottomRight.y - center.y) * factor;
}

Point Rectangle::getCenter() const {
	return Point((topLeft.x + bottomRight.x) / 2.0, (topLeft.y + bottomRight.y) / 2.0);
}

std::string Rectangle::getName() const {
	return "Rectangle";
}

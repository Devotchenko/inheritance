#include "rectangle.h"

Rectangle::Rectangle(const Point& topLeft, const Point& bottomRight)
    : topLeft(topLeft), bottomRight(bottomRight) {}

double Rectangle::getArea() const {
    return abs((bottomRight.x - topLeft.x) * (topLeft.y - bottomRight.y));
}

void Rectangle::scale(double factor) {
    Point center = getCenter();
    topLeft.x = center.x + (topLeft.x - center.x) * factor;
    topLeft.y = center.y + (topLeft.y - center.y) * factor;
    bottomRight.x = center.x + (bottomRight.x - center.x) * factor;
    bottomRight.y = center.y + (bottomRight.y - center.y) * factor;
}

Point Rectangle::getCenter() const {
    return Point((topLeft.x + bottomRight.x) / 2, (topLeft.y + bottomRight.y) / 2);
}

std::string Rectangle::getName() const {
    return "RECTANGLE";
}

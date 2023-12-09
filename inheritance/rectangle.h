#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape {
    Point topLeft, bottomRight;

public:
    Rectangle(const Point& topLeft, const Point& bottomRight);
    double getArea() const override;
    void scale(double factor) override;
    Point getCenter() const override;
    std::string getName() const override;
};

#endif // RECTANGLE_H

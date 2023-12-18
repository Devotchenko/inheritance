#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle : public Shape {
    Point a, b, c;
public:
    Triangle(const Point& a, const Point& b, const Point& c);
    double getArea() const override;
    void scale(double factor) override;
    Point getCenter() const override;
    std::string getName() const override;
};

#endif // TRIANGLE_H


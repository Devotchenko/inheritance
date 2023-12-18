#ifndef SHAPE_H
#define SHAPE_H
#include "point.h"
#include <string>

class Shape {
public:
    virtual ~Shape() {}
    virtual double getArea() const = 0;
    virtual void scale(double factor) = 0;
    virtual Point getCenter() const = 0;
    virtual std::string getName() const = 0;

    bool operator<(const Shape& other) const {
        return this->getArea() < other.getArea();
    }
};

#endif // SHAPE_H


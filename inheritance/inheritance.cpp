#include <iostream>
#include <vector>
#include <algorithm>
#include "shape.h"
#include "rectangle.h"
#include "triangle.h"

int main() {
    std::vector<Shape*> shapes;

    // Создание фигур
    shapes.push_back(new Rectangle(Point(0, 0), Point(4, 3)));
    shapes.push_back(new Triangle(Point(0, 0), Point(4, 0), Point(2, 3))); 
    shapes.push_back(new Rectangle(Point(0, 0), Point(2, 2))); 
    shapes.push_back(new Triangle(Point(0, 0), Point(2, 0), Point(1, 1.732))); 
	shapes.push_back(new Rectangle(Point(1, 1), Point(1, 1)));

    // Сортировка фигур
    std::sort(shapes.begin(), shapes.end(), [](const Shape* a, const Shape* b) {
        return *a < *b;
        });

    // Вывод информации о фигурах
    for (const auto& shape : shapes) {
        std::cout << shape->getName() << ": Center = (" << shape->getCenter().x << ", " << shape->getCenter().y
            << "), square = " << shape->getArea() << std::endl;
    }

    // Масштабирование всех фигур
    double scaleFactor = 6.0; 
    for (auto& shape : shapes) {
        shape->scale(scaleFactor);
    }

    std::cout << "\nAfter scaling:" << std::endl;

    // Вывод информации после масштабирования
    for (const auto& shape : shapes) {
        std::cout << shape->getName() << ": Center = (" << shape->getCenter().x << ", " << shape->getCenter().y
            << "), square = " << shape->getArea() << std::endl;
    }

    // Освобождение ресурсов
    for (auto& shape : shapes) {
        delete shape;
    }

    return 0;
}

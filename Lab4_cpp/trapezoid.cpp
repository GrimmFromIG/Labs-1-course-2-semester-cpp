#include "trapezoid.h"

Trapezoid::Trapezoid(const std::vector<std::pair<double, double>>& v) : Shape(v) {}

double Trapezoid::area() const {
    double a = sideLength(0, 1);
    double b = sideLength(2, 3);
    double h = std::abs(vertices[0].second - vertices[2].second);
    return 0.5 * (a + b) * h;
}

double Trapezoid::perimeter() const {
    return sideLength(0, 1) + sideLength(1, 2) + sideLength(2, 3) + sideLength(3, 0);
}

void Trapezoid::printData() const {
    std::cout << "Trapezoid: area = " << area() << ", perimeter = " << perimeter() << std::endl;
}


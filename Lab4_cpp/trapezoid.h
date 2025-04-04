#pragma once

#include "shapes.h"

class Trapezoid : public Shape {
public:
    Trapezoid(const std::vector<std::pair<double, double>>& v);
    double area() const;
    double perimeter() const;
    void printData() const override;
};
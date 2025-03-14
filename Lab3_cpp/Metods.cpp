#include "Metods.h"
#include <cmath>

Rectangle::Rectangle() : coords{0, 0, 1, 1} {}
Rectangle::Rectangle(double x1, double y1, double x2, double y2) : coords{x1, y1, x2, y2} {}
Rectangle::Rectangle(const Rectangle& other) : coords{other.coords} {}

double Rectangle::area() const {
    return std::abs((coords[2] - coords[0]) * (coords[3] - coords[1]));
}

double Rectangle::perimeter() const {
    return 2 * (std::abs(coords[2] - coords[0]) + std::abs(coords[3] - coords[1]));
}

void Rectangle::setCoordinates(double x1, double y1, double x2, double y2) {
    coords = {x1, y1, x2, y2};
}

void Rectangle::setCoordinates(const std::array<double, 4>& vertices) {
    coords = vertices;
}

void Rectangle::display() const {
    std::cout << "Прямокутник: (" << coords[0] << ", " << coords[1] << ") -> ("
              << coords[2] << ", " << coords[3] << ")"
              << " | Площа: " << area()
              << ", Периметр: " << perimeter()
              << std::endl;
}

Rectangle Rectangle::operator/(double value) const {
    return Rectangle(coords[0], coords[1],
                     coords[0] + (coords[2] - coords[0]) / value,
                     coords[1] + (coords[3] - coords[1]) / value);
}

Rectangle Rectangle::operator-(double value) const {
    return Rectangle(coords[0], coords[1],
                     coords[2] - value, coords[3] - value);
}

Rectangle Rectangle::operator-(const Rectangle& other) const {
    return Rectangle(coords[0] - other.coords[0], coords[1] - other.coords[1],
                     coords[2] - other.coords[2], coords[3] - other.coords[3]);
}



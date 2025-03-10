#include "Metods.h"

// Конструктор за замовчуванням
Rectangle::Rectangle() : x1(0), y1(0), x2(1), y2(1) {}
// Конструктор з параметрами
Rectangle::Rectangle(double x1, double y1, double x2, double y2)
    : x1(x1), y1(y1), x2(x2), y2(y2) {}
// Конструктор копіювання
Rectangle::Rectangle(const Rectangle& other)
    : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2) {}

double Rectangle::area() const {
    return abs((x2 - x1) * (y2 - y1));
}

double Rectangle::perimeter() const {
    return 2 * (abs(x2 - x1) + abs(y2 - y1));
}

Rectangle Rectangle::operator-(double value) const {
    return Rectangle(x1, y1, x2 - value, y2 - value);
}

Rectangle Rectangle::operator/(double value) const {
    return Rectangle(x1, y1, x1 + (x2 - x1) / value, y1 + (y2 - y1) / value);
}

Rectangle Rectangle::operator-(const Rectangle& other) const {
    return Rectangle(x1 - other.x1, y1 - other.y1, x2 - other.x2, y2 - other.y2);
}

void Rectangle::display() const {
    std::cout << "Прямокутник: (" << x1 << ", " << y1 << ") -> (" << x2 << ", " << y2 << ")" 
              << " | Площа: " << area() << ", Периметр: " << perimeter() << std::endl;
}


#pragma once

#include <iostream>

class Rectangle {
private:
    double x1, y1, x2, y2;

public:
    Rectangle();  // За замовчуванням
    Rectangle(double x1, double y1, double x2, double y2); // З параметрами
    Rectangle(const Rectangle& other); // Конструктор копіювання
    
    double area() const;
    double perimeter() const;
    
    Rectangle operator-(double value) const;  // "Зменшення" розміру
    Rectangle operator/(double value) const;  // Ділення розміру
    Rectangle operator-(const Rectangle& other) const;  // Віднімання прямокутників
    
    void display() const;
};


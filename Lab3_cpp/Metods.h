#pragma once

#include <array>
#include <iostream>

class Rectangle {
private:
    std::array<double, 4> coords;

public:
    // Конструктори
    Rectangle();
    Rectangle(double x1, double y1, double x2, double y2);
    Rectangle(const Rectangle& other);
    
    double area() const;      
    double perimeter() const;  
    
    void setCoordinates(double x1, double y1, double x2, double y2); 
    void setCoordinates(const std::array<double, 4>& vertices);      
    
    void display() const;
    
    Rectangle operator/(double value) const;                      
    Rectangle operator-(double value) const;                       
    Rectangle operator-(const Rectangle& other) const;              
};


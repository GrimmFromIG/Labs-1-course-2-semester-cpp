#pragma once

#include <cmath>
#include <vector>
#include <iostream>

class Shape {
protected:
    std::vector<std::pair<double, double>> vertices; 

public:
    Shape(const std::vector<std::pair<double, double>>& v);
    virtual ~Shape() {}
    double sideLength(int i, int j) const; 
    virtual void printData() const = 0; 
};


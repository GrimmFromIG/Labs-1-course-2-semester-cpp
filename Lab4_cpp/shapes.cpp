#include "shapes.h"

Shape::Shape(const std::vector<std::pair<double, double>>& v) : vertices(v) {}

double Shape::sideLength(int i, int j) const {
    double dx = vertices[j].first - vertices[i].first;
    double dy = vertices[j].second - vertices[i].second;
    return std::sqrt(dx * dx + dy * dy);
}


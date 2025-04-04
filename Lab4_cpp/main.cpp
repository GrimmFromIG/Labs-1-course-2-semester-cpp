#include "trapezoid.h"

int main()
{
    std::vector<std::pair<double, double>> coords = {{0, 0}, {4, 0}, {3, 2}, {1, 2}};
    Trapezoid trap(coords);
    trap.printData();
    return 0;
}
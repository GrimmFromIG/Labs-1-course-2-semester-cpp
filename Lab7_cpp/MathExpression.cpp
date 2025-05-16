#include "MathExpression.h"
#include <cmath>
#include <stdexcept>

MathExpression::MathExpression() : a(0), b(0), c(0), d(1) {}

MathExpression::MathExpression(double a, double b, double c, double d) 
    : a(a), b(b), c(c), d(d) {}

void MathExpression::setA(double value) { a = value; }
void MathExpression::setB(double value) { b = value; }
void MathExpression::setC(double value) { c = value; }
void MathExpression::setD(double value) { 
    if (value == 0) {
        throw std::invalid_argument("D cannot be zero");
    }
    d = value; 
}

double MathExpression::getA() const { return a; }
double MathExpression::getB() const { return b; }
double MathExpression::getC() const { return c; }
double MathExpression::getD() const { return d; }

double MathExpression::customLog10(double value) const {
    if (value <= 0) {
        throw std::domain_error("Logarithm argument must be positive");
    }
    
    const double ln10 = 2.30258509299404568402;
    return log(value) / ln10;
}

double MathExpression::calculateExpression() const {
    try
    {
        if (d == 1 || b + c == 0 ) {
            throw std::invalid_argument("D cannot be 1 and B + C cannot be zero");
        }
        else if (d == 1) {
            throw std::invalid_argument("D cannot be 1");
        }
        else if (b + c == 0 ) {
            throw std::invalid_argument("B + C cannot be zero");
        }
        double logArgument = 4 * b - c;
        double logarithm = customLog10(logArgument);
        double expression = (logarithm * a) / (b + c / d - 1);
        
        return expression;
    } catch (const std::exception& e) {
        throw;
    }
}
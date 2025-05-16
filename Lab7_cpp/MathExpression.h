#pragma once

#include <stdexcept>

class MathExpression {
private:
    double a;
    double b;
    double c;
    double d;
    
    double customLog10(double value) const;

public:
    MathExpression();
    MathExpression(double a, double b, double c, double d);

    void setA(double value);
    void setB(double value);
    void setC(double value);
    void setD(double value);

    double getA() const;
    double getB() const;
    double getC() const;
    double getD() const;

    double calculateExpression() const;
};




#include <iostream>
#include <vector>
#include "MathExpression.h"

int main() {
    try {
        std::vector<MathExpression> expressions = {
            MathExpression(1, 2, 50, 4),
            MathExpression(2, 3, 4, 5),
            MathExpression(3, 4, -4, 1) 
        };

        for (size_t i = 0; i < expressions.size(); ++i) {
            try {
                double result = expressions[i].calculateExpression();
                std::cout << "Expression " << i+1 << " result: " << result << std::endl;
            } catch (const std::exception& e) {
                std::cerr << "Error calculating expression " << i+1 << ": " << e.what() << std::endl;
            }
        }

    } catch (...) {
        std::cerr << "Unexpected error occurred" << std::endl;
        return 1;
    }

    return 0;
}

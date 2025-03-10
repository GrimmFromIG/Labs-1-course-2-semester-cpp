#include <iostream>
#include "ExtendedString.h"

int main() {
    std::cout << "Enter a numeric string: " << std::endl;

    std::string input;

    std::cin >> input;

    ExtendedString strObj(input);

    std::cout << "Initial string: " << strObj.getString() << std::endl;

    std::cout << "String length: " << strObj.getLength() << std::endl;

    strObj.removeChar5();

    std::cout << "String after deleting char '5': " << strObj.getString() << std::endl;

    std::cout << "New string length: " << strObj.getLength() << std::endl;

    return 0;
} 
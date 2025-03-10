#include "StringProcessor.h"
#include <iostream>

int main()
{
    std::cout << "Enter a numeric string: " << std::endl;
    std::string input;
    std::cin >> input;
    StringProcessor strObj(input);

    std::cout << "Initial string: " << strObj.getString() << std::endl;
    std::cout << "String length: " << strObj.getLength() << std::endl;

   
    strObj.removeFives();
    std::cout << "String after deleting char '5': " << strObj.getString() << std::endl;
    std::cout << "New string length: " << strObj.getLength() << std::endl;

    return 0;
}

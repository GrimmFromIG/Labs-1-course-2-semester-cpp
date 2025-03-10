#include "StringProcessor.h"
#include <iostream>
#include <algorithm>

//                             
StringProcessor::StringProcessor() : str("") {}

//                         
StringProcessor::StringProcessor(const std::string& inputStr)
{
    if (isNumeric(inputStr))
    {
        this->str = inputStr;
    }
    else
    {
        std::cout << "Error: String contains non-numeric symbols. Enter a valid numeric string.\n";
        this->str = getValidNumericInput();
    }
}

//                      
StringProcessor::StringProcessor(const StringProcessor& other) : str(other.str) {}

StringProcessor::~StringProcessor()
{
    std::cout << "Object destroyed. Stored string: " << str << std::endl;
}

bool StringProcessor::isNumeric(const std::string& str)
{
    return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
}

std::string StringProcessor::getValidNumericInput()
{
    std::string input;
    bool isValid;

    do
    {
        std::cout << "Enter a numeric string: ";
        std::cin >> input;
        isValid = isNumeric(input);

        if (!isValid)
        {
            std::cout << "Error: String contains non-numeric symbols. Try again.\n";
        }

    } while (!isValid);

    return input;
}

std::string StringProcessor::getString() const
{
    return str;
}

size_t StringProcessor::getLength() const
{
    return str.length();
}

void StringProcessor::removeFives()
{
    str.erase(std::remove(str.begin(), str.end(), '5'), str.end());
}

void StringProcessor::SetString(const std::string& newStr)
{
    if (isNumeric(newStr))
    {
        this->str = newStr;
    }
    else
    {
        std::cout << "Error: New string contains non-numeric symbols. Keeping the old string.\n";
    }
}


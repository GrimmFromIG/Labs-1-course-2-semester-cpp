#include "ExtendedString.h"

bool ExtendedString::isNumeric(const std::string& str)
{
    return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
}

std::string ExtendedString::getValidNumericInput()
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
            std::cout << "String contain non numeric symbols. Try again.\n";
        }

    } while (!isValid);

    return input;
}

ExtendedString::ExtendedString(const std::string& str)
{
    if (isNumeric(str))
    {
        data = str;
    }
    else
    {
        std::cout << "String contain non numeric symbols. Try again.\n";
        data = getValidNumericInput();
    }
}

std::string ExtendedString::getString() const
{
    return data;
}

size_t ExtendedString::getLength() const
{
    return data.length();
}

void ExtendedString::removeChar5()
{
    data.erase(std::remove(data.begin(), data.end(), '5'), data.end());
}


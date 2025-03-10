#ifndef EXTENDEDSTRING_H
#define EXTENDEDSTRING_H

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

class ExtendedString
{
private:
    std::string data;

    static bool isNumeric(const std::string& str);
    static std::string getValidNumericInput();

public:
    ExtendedString(const std::string& str);

    std::string getString() const;
    size_t getLength() const;
    void removeChar5();
};

#endif // EXTENDEDSTRING_H

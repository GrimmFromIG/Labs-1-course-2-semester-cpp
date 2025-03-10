#ifndef STRINGPROCESSOR_H
#define STRINGPROCESSOR_H

#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

class StringProcessor 
{
private:
    std::string str;
    static bool isNumeric(const std::string& str);
    static std::string getValidNumericInput();

public:
    StringProcessor();
    StringProcessor(const std::string& inputStr);
    StringProcessor(const StringProcessor& other);

    ~StringProcessor();

    size_t getLength() const;
    void removeFives();
    std::string getString() const;
    void SetString(const std::string& newStr);
};

#endif


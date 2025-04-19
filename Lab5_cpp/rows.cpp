#include "rows.h"
#include <iostream>

Row::Row(const std::string& val) : value(val) {}

int Row::getLength() const {
    return value.length();
}

void Row::expand() {
}

void Row::print() const {
    std::cout << value << " (length: " << getLength() << ")" << std::endl;
}

Digits::Digits(const std::string& val) : Row(val) {}
int Digits::getLength() const {
    return value.length();
}

void Digits::expand() {
    std::string result;
    for (char ch : value) {
        result += ch;
        result += ch;
    }
    value = result;
}

Symbols::Symbols(const std::string& val) : Row(val) {}
int Symbols::getLength() const {
    return value.length();
}

void Symbols::expand() {
    std::string result;
    for (char ch : value) {
        result += ch;
        if (ch == 'k') result += ch; 
    }
    value = result;
}
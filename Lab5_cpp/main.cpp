#include <iostream>
#include <vector>
#include "rows.h"

std::string generateRandomDigitsString(int maxLength = 10) {
    int len = rand() % maxLength + 1;
    std::string result;
    for (int i = 0; i < len; ++i) {
        result += '0' + rand() % 10;
    }
    return result;
}

std::string generateRandomSymbolStringWithK(int maxLength = 10) {
    int len = rand() % (maxLength - 1) + 1;
    std::string result;
    for (int i = 0; i < len; ++i) {
        char ch = 'a' + rand() % 26;
        result += ch;
    }
    int insertPos = rand() % (len + 1);
    result.insert(insertPos, "k");
    return result;
}

Row* generateRandomRow() {
    if (rand() % 2 == 0) {
        return new Digits(generateRandomDigitsString());
    } else {
        return new Symbols(generateRandomSymbolStringWithK());
    }
}

void process(Row* r) {
    std::cout << "Before: ";
    r->print();
    r->expand();
    std::cout << "After: ";
    r->print();
    std::cout << std::endl;
}

int main() {
    srand(static_cast<unsigned>(time(0)));
    std::vector<Row*> rows;

    for (int i = 0; i < 3; ++i) {
        rows.push_back(generateRandomRow());
    }

    for (Row* r : rows) {
        process(r);
        delete r;
    }
    
    return 0;
}
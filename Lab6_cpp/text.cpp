#include "text.h"
#include <algorithm>
#include <cctype>
#include <climits>

Row::Row(const std::string& str) : data(str) {}

void Row::setData(const std::string& str) {
    data = str;
}

std::string Row::getData() const {
    return data;
}

void Row::trimSpaces() {
    size_t start = data.find_first_not_of(" \t");
    if (start != std::string::npos) {
        data = data.substr(start);
    }
    
    size_t end = data.find_last_not_of(" \t");
    if (end != std::string::npos) {
        data = data.substr(0, end + 1);
    } else if (data.size() > 0) {
        data.clear();
    }
}

void Row::replaceMultipleSpaces() {
    std::string result;
    bool prevSpace = false;
    
    for (char c : data) {
        if (c == ' ' || c == '\t') {
            if (!prevSpace) {
                result += ' ';
                prevSpace = true;
            }
        } else {
            result += c;
            prevSpace = false;
        }
    }
    
    data = result;
}

double Row::calculateConsonantPercentage() const {
    if (data.empty()) return 0.0;
    
    const std::string consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    const std::string vowels = "aeiouAEIOU";
    
    size_t consonantCount = 0;
    size_t letterCount = 0;
    
    for (char c : data) {
        if (isalpha(c)) {
            letterCount++;
            if (consonants.find(c) != std::string::npos) {
                consonantCount++;
            }
        }
    }
    
    return (letterCount == 0) ? 0.0 : (static_cast<double>(consonantCount) / letterCount) * 100.0;
}

size_t Row::length() const {
    return data.length();
}

void TextContainer::addRow(const Row& row) {
    rows.push_back(row);
}

void TextContainer::removeRow(size_t index) {
    if (index < rows.size()) {
        rows.erase(rows.begin() + index);
    }
}

void TextContainer::clearText() {
    rows.clear();
}

size_t TextContainer::getShortestRowLength() const {
    if (rows.empty()) return 0;
    
    size_t minLength = SIZE_MAX;
    for (const Row& row : rows) {
        size_t len = row.length();
        if (len < minLength) {
            minLength = len;
        }
    }
    return minLength;
}

double TextContainer::getConsonantPercentage() const {
    if (rows.empty()) return 0.0;
    
    size_t totalConsonants = 0;
    size_t totalLetters = 0;
    
    for (const Row& row : rows) {
        std::string data = row.getData();
        for (char c : data) {
            if (isalpha(c)) {
                totalLetters++;
                if (tolower(c) != 'a' && tolower(c) != 'e' && tolower(c) != 'i' && 
                    tolower(c) != 'o' && tolower(c) != 'u') {
                    totalConsonants++;
                }
            }
        }
    }
    
    return (totalLetters == 0) ? 0.0 : (static_cast<double>(totalConsonants) / totalLetters) * 100.0;
}

void TextContainer::processSpaces() {
    for (Row& row : rows) {
        row.replaceMultipleSpaces();
        row.trimSpaces();
    }
}

size_t TextContainer::size() const {
    return rows.size();
}

const Row& TextContainer::getRow(size_t index) const {
    return rows[index];
}
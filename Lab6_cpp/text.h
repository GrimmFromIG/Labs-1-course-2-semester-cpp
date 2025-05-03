#pragma once

#include <vector>
#include <string>

class Row {
private:
    std::string data;

public:
    Row(const std::string& str = "");
    
    void setData(const std::string& str);
    std::string getData() const;
    
    void trimSpaces();
    void replaceMultipleSpaces();
    double calculateConsonantPercentage() const;
    size_t length() const;
};

class TextContainer {
private:
    std::vector<Row> rows;

public:
    void addRow(const Row& row);
    void removeRow(size_t index);
    void clearText();
    size_t getShortestRowLength() const;
    double getConsonantPercentage() const;
    void processSpaces();
    size_t size() const;
    Row& getRow(size_t index);
    const Row& getRow(size_t index) const; 
};



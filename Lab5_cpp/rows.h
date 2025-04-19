#pragma once

#include <string>

class Row {
protected:
    std::string value;

public:
    Row(const std::string& val);
    virtual ~Row() = default;

    virtual int getLength() const;
    virtual void expand();
    virtual void print() const;
};

class Digits : public Row {
public:
    Digits(const std::string& val);

    int getLength() const override;
    void expand() override;
};

class Symbols : public Row {
public:
    Symbols(const std::string& val);

    int getLength() const override;
    void expand() override;
};



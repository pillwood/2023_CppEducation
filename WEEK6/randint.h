#ifndef RANDINT_H
#define RANDINT_H
#include <string>

class RandInt {
public:
    RandInt(int min, int max, const std::string& name);
    void print() const;

private:
    int value;
    std::string name;
};

#endif
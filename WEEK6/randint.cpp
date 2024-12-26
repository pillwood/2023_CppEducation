#include "randint.h"
#include <random>
#include <ctime>
#include <iostream>

RandInt::RandInt(int min, int max, const std::string& name) : name(name) {
    std::mt19937 gen(std::time(nullptr));
    std::uniform_int_distribution<int> distribution(min, max);
    value = distribution(gen);
}

void RandInt::print() const {
    std::cout << name << ": " << value << std::endl;
}
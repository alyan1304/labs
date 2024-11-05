#pragma once
#include <iostream>

class ProperFraction {
private:
    int numerator;
    int denominator;
public:
    ProperFraction(int _numerator, int _denominator);
    ProperFraction(const ProperFraction &other);
    int getNumerator();
    int getDenominator();
    ProperFraction() = delete; // почему работает только без реализации?
    void reduceFraction();
    ProperFraction operator+(const ProperFraction &other);
    ProperFraction operator*(const ProperFraction &other);
    ProperFraction operator/(const ProperFraction &other);
};
std::ostream& operator<<(std::ostream &out, ProperFraction &fraction);
#include <iostream>
#include "fraction.h"

ProperFraction::ProperFraction(int _numerator, int _denominator) {
    numerator = _numerator;
    if (_denominator == 0) {
        std::cout << "Denominator cannot be 0. Input another one";
        std::cin >> denominator;
        } else {
        denominator = _denominator;
        }
        reduceFraction();
    };
ProperFraction::ProperFraction(const ProperFraction &other) {
    numerator = other.numerator;
    denominator = other.denominator;
};
int ProperFraction::getNumerator() {
    return numerator;
};
int ProperFraction::getDenominator() {
    return denominator;
};
void ProperFraction::reduceFraction() {
    if (numerator != 0) {
        int smaller = (denominator <= numerator) ? denominator : numerator;
        for (int i = smaller; i > 0; i--) {
            if (numerator % i == 0 && denominator % i == 0) {
                numerator /= i;
                denominator /= i;
            }
        }
    }
};
ProperFraction ProperFraction::operator+(const ProperFraction &other) {
    int resNumerator;
    int resDenominator;
    resDenominator = denominator * other.denominator;
    resNumerator = (resDenominator / denominator) * numerator + (resDenominator / other.denominator) * other.numerator;
    ProperFraction result(resNumerator, resDenominator);
    result.reduceFraction();
    return result;
} 
ProperFraction ProperFraction::operator*(const ProperFraction &other) {
    int resNumerator;
    int resDenominator;
    resDenominator = denominator * other.denominator;
    resNumerator = numerator * other.numerator;
    ProperFraction result(resNumerator, resDenominator);
    result.reduceFraction();
    return result;
} 
ProperFraction ProperFraction::operator/(const ProperFraction &other) {
    int resNumerator;
    int resDenominator;
    resDenominator = denominator * other.numerator;
    resNumerator = numerator * other.denominator;
    ProperFraction result(resNumerator, resDenominator);
    result.reduceFraction();
    return result;
} 
std::ostream& operator<<(std::ostream &out, ProperFraction &fraction) {
        if (abs(fraction.getNumerator()) >= abs(fraction.getDenominator())) {
        int integerPart = fraction.getNumerator() / fraction.getDenominator();
        char* minusOrNothing;
        if (integerPart >=0) {
            minusOrNothing = " ";
        } else {
            minusOrNothing = "-";
        }
        int newNumerator = abs(fraction.getNumerator()) - abs(fraction.getDenominator()) * abs(integerPart);
            if (newNumerator !=0) {
                out << std::endl << "   " << newNumerator << std::endl << minusOrNothing <<
                abs(integerPart) << " -" << std::endl << "   " << abs(fraction.getDenominator()) << std::endl; 
            } else {
                out << std::endl << integerPart << std::endl;
            }
        } else if (double(fraction.getNumerator()) / double(fraction.getDenominator()) >= 0) {
            out << std::endl << abs(fraction.getNumerator()) << std::endl <<
            "-" << std::endl << abs(fraction.getDenominator()) << std::endl;
        } else {
            out << std::endl << "  " << abs(fraction.getNumerator()) << std::endl <<
            "- -" << std::endl << "  " << abs(fraction.getDenominator()) << std::endl;
        }
        return out;
};

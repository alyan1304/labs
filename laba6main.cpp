#include "fraction.h"

int main() {
int num1;
int denom1;
int num2;
int denom2;

std::cout << "Input numerator and denominator of the first fraction ";
std::cin >> num1 >> denom1;
ProperFraction fraction1(num1, denom1);
std::cout << fraction1;

std::cout << "Input numerator and denominator of the second fraction ";
std::cin >> num2 >> denom2;
ProperFraction fraction2(num2, denom2);
std::cout << fraction2;

std::cout << fraction1 + fraction2 << fraction1 * fraction2 << fraction1 / fraction2;

return 0;
}

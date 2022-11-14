#include <iostream>

#include "fraction.h"

int main()
{
	Fraction f1(1, 2), f2(4, 2);
	Fraction f3 = f1 + f2, f4 = f1 * f2, f5 = f1 * 2, f6 = f2 - f1, f7 = f1 / f2;

	std::cout << f3.getNumerator() << '/' << f3.getDenominator() << '\n';
	std::cout << f4.getNumerator() << '/' << f4.getDenominator() << '\n';
	std::cout << f5.getNumerator() << '/' << f5.getDenominator() << '\n';
	std::cout << f6.getNumerator() << '/' << f6.getDenominator() << '\n';
	std::cout << f7.getNumerator() << '/' << f7.getDenominator() << '\n';
	return 0;
}

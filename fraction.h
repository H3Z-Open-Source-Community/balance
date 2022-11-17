#pragma once

#include <cmath>

namespace math
{
	template <class Number>
	Number gcd(Number n1, Number n2)
	{
		if (n2 > n1)
		{
			std::swap(n1, n2);
		}
		if (n2 == 0)
		{
			return n1;
		}
		return gcd(n2, n1 % n2);
	}

	template <class Number>
	Number lcm(Number n1, Number n2)
	{
		return n1 * n2 / gcd(n1, n2);
	}

	template <class Number>
	Number anyAbs(Number num)
	{
		if (num < 0)
		{
			return -num;
		}
		return num;
	}
}

class Fraction
{
	private:
		int denominator, numerator;
	public:
		Fraction(int denominator, int numerator);
		Fraction(int num);

		void irregularFraction();
		void operator=(const Fraction & frac);
		void operator=(const int num);
		bool operator==(Fraction & frac);
		bool operator!=(Fraction & frac);
		Fraction operator+(const Fraction & frac);
		Fraction operator-(const Fraction & frac);
		Fraction operator*(const Fraction & frac);
		Fraction operator/(const Fraction & frac);
		bool operator<(const Fraction & frac);
		bool operator>(const Fraction & frac);
		bool operator<=(const Fraction & frac);
		bool operator>=(const Fraction & frac);
		Fraction operator-() 		const;
		Fraction inverseFraction()  const;

		friend Fraction operator+(const int num, const Fraction & frac);
		friend Fraction operator-(const int num, const Fraction & frac);
		friend Fraction operator*(const int num, const Fraction & frac);
		friend Fraction operator/(const int num, const Fraction & frac);
		friend bool operator<(const int num, const Fraction & frac);
		friend bool operator>(const int num, const Fraction & frac);
		friend bool operator<=(const int num, const Fraction & frac);
		friend bool operator>=(const int num, const Fraction & frac);

		Fraction operator+(const int num);
		Fraction operator-(const int num);
		Fraction operator*(const int num);
		Fraction operator/(const int num);
		bool operator<(const int num);
		bool operator>(const int num);
		bool operator<=(const int num);
		bool operator>=(const int num);

		int getNumerator() 		const;
		int getDenominator()	const;

		Fraction abs();
};

#include "fraction.h"

Fraction::Fraction(int numerator, int denominator)
{
	if (denominator == 0)
	{
		throw "Error: Denominator can not be zero.";
	}
	this -> numerator   = numerator;
	this -> denominator = denominator;
}

Fraction::Fraction(int num)
{
	this -> numerator   = num;
	this -> denominator = 1;
}

void Fraction::irregularFraction()
{
	if ((this -> numerator) < 0 && (this -> denominator) < 0)
	{
		this -> numerator   = -(this -> numerator);
		this -> denominator = -(this -> denominator);
	}
	const int g = math::gcd(std::abs(this -> numerator), std::abs(this -> denominator));
	(this -> numerator)   /= g;
	(this -> denominator) /= g;
	return ;
}

void Fraction::operator=(const Fraction & frac)
{
	this -> numerator   = frac.numerator;
	this -> denominator = frac.denominator;
	return ;
}

void Fraction::operator=(const int num)
{
	this -> numerator   = num;
	this -> denominator = 1;
	return ;
}

bool Fraction::operator==(Fraction & frac)
{
	this -> irregularFraction();
	frac.irregularFraction();

	if ((this -> numerator)   == frac.numerator &&
		(this -> denominator) == frac.denominator)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Fraction Fraction::operator-() const
{
	Fraction result(-(this -> numerator), denominator);
	return result;
}

Fraction Fraction::inverseFraction() const 
{
	if ((this -> numerator) == 0)
	{
		throw "Error: The numerator of this fraction is zero";
	}
	Fraction result(this -> denominator, this -> numerator);
	return result;
}

Fraction Fraction::operator+(const Fraction & frac)
{
	const int d = math::lcm(std::abs(this -> denominator), std::abs(frac.denominator));
	const int n = (this -> numerator) * (d / (this -> denominator))
				+ frac.numerator      * (d / frac.denominator);
	Fraction result(n, d);
	return result;
}

Fraction Fraction::operator-(const Fraction & frac)
{
	return (*this) + (-frac);
}

Fraction Fraction::operator*(const Fraction & frac)
{
	Fraction result((this -> numerator)   * frac.numerator, 
					(this -> denominator) * frac.denominator);
	result.irregularFraction();
	return result;
}

Fraction Fraction::operator/(const Fraction & frac)
{
	if (frac.numerator == 0)
	{
		throw "Error: Can not divide by zero";
	}

	return (*this) * (frac.inverseFraction());
}

Fraction Fraction::operator+(const int num)
{
	Fraction f(num);
	return (*this) + f;
}

Fraction Fraction::operator-(const int num)
{
	Fraction f(num);
	return (*this) - f;
}

Fraction Fraction::operator*(const int num)
{
	Fraction f(num);
	return (*this) * f;
}

Fraction Fraction::operator/(const int num)
{
	Fraction f(num);
	return (*this) / f;
}

Fraction operator+(const int num, Fraction & frac)
{
	Fraction f(num);
	return f + frac;
}

Fraction operator-(const int num, Fraction & frac)
{
	Fraction f(num);
	return f - frac;
}

Fraction operator*(const int num, Fraction & frac)
{
	Fraction f(num);
	return f * frac;
}

Fraction operator/(const int num, Fraction & frac)
{
	Fraction f(num);
	return f / frac;
}

int Fraction::getNumerator()	const
{
	return (this -> numerator);
}

int Fraction::getDenominator() 	const
{
	return (this -> denominator);
}

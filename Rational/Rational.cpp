#include "Rational.h"

void Rational::Normalize()
{
	int g = gcd(abs(num), abs(den));
	if (num>0 && den>0 || num<0 && den<0)
	{
		num = abs(num) / g;
		den = abs(den) / g;
	}
	else
	{
		num = -abs(num) / g;
		den = abs(den) / g;
	}
}

int Rational::gcd(int a, int b)
{
	while (a != b)
		if (a > b) a -= b;
		else b -= a;
		return a;
}

Rational::Rational(int a, int b)
{
	if (b == 0) throw DivideByZeroException("Incorrect parameter...");
	else
		if (a == 0)
		{
			num = 0;
			den = 1;
		}
		else
		{
			num = a; den = b;
			Normalize();
		}
}

Rational::Rational(double d)
{
	int n = 0;
	int sign = +1;
	if (d<0) sign = -1;
	d = abs(d);
	while (d > static_cast<int>(d))
	{
		d *= 10;
		++n;
	}
	num = sign * static_cast<int>(d);
	den = 1;
	for (int i = 1; i <= n; ++i)
		den *= 10;
	Normalize();
}

void Rational::Show() const
{
	std::cout << num << "/" << den << std::endl;
}

bool Rational::IsZero() const
{
	return num == 0;
}

Rational Rational::operator+(const Rational &r2)
{
	return Rational(num*r2.den + r2.num*den, den*r2.den);
}

Rational Rational::operator-(const Rational &r2)
{
	return Rational(num*r2.den - r2.num*den, den*r2.den);
}

Rational Rational::operator*(const Rational &r2)
{
	return Rational(num*r2.num, den*r2.den);
}

Rational Rational::operator/(const Rational &r2)
{
	if (r2.IsZero())
		throw DivideByZeroException();
	else
		return Rational(num*r2.den, den*r2.num);
}

Rational Rational::Sum(const Rational &r2)
{
	return Rational(this->num*r2.den + r2.num*den, den*r2.den);
}

Rational Rational::Sub(const Rational &r2)
{
	return Rational(num*r2.den - r2.num*den, den*r2.den);
}

Rational Rational::Mult(const Rational &r2)
{
	return Rational(num*r2.num, den*r2.den);
}

Rational Rational::Quot(const Rational &r2)
{
	if (r2.IsZero())
		throw "Division by zero!";
	else
		return Rational(num*r2.den, den*r2.num);
}

std::ostream & operator<<(std::ostream &out, const Rational &r)
{
	out << r.num << "/" << r.den;
	return out;
}

std::istream & operator>>(std::istream &ent, Rational &r)
{
	std::cout << "numerator: "; ent >> r.num;
	std::cout << "denominator: "; ent >> r.den;
	r.Normalize();
	return ent;
}

Rational Sum(const Rational &r1, const Rational &r2)
{
	/*Rational result;
	result.num = r1.num*r2.den + r2.num*r1.den;
	result.den = r1.den*r2.den;
	return result;*/
	return Rational(r1.num*r2.den + r2.num*r1.den, r1.den*r2.den);
}

Rational Sub(const Rational &r1, const Rational &r2)
{
	return Rational(r1.num*r2.den - r2.num*r1.den, r1.den*r2.den);
}

Rational Mult(const Rational &r1, const Rational &r2)
{
	return Rational(r1.num*r2.num, r1.den*r2.den);
}

Rational Quot(const Rational &r1, const Rational &r2)
{
	if (r2.IsZero())
		throw "Division by zero!";
	else
		return Rational(r1.num*r2.den, r1.den*r2.num);
}

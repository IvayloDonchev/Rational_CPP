#pragma once
#include <iostream>
#include <cmath>
#include "DivideByZeroException.h"

class Rational
{
private:
	int num;			// числител
	int den;			// знаменател
	void Normalize();	// съкращава дробта
public:
	static int gcd(int, int);		// Н.О.Д.
	Rational() : num(0), den(1) {}	// default constructor
	Rational(int, int);				// constructor
	Rational(double);				// конструира Rational от double 
	bool IsZero() const;
	bool operator!() { return num == 0; }
	double ToDouble() const { return static_cast<double>(num) / den; }
	operator double() { return static_cast<double>(num) / den; }	// преобразува до тип double
	Rational operator+(const Rational&);
	Rational operator-(const Rational&);
	Rational operator*(const Rational&);
	Rational operator/(const Rational&);
	friend std::ostream& operator <<(std::ostream&, const Rational&);		// предефинира операцията за извеждане
	friend std::istream& operator >>(std::istream&, Rational&);			// предефинира операцията за въвеждане
};

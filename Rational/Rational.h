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
	void Show() const;				// показва на екрана
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
	Rational Sum(const Rational&);   // сума с метод на класа
	Rational Sub(const Rational&);   // разлика с метод на класа
	Rational Mult(const Rational&);  // произведение с метод на класа
	Rational Quot(const Rational&);  // частно с метод на класа
	friend Rational Sum(const Rational&, const Rational&);  // сума с външна ф-я
	friend Rational Sub(const Rational&, const Rational&);  // разлика
	friend Rational Mult(const Rational&, const Rational&); // произведение
	friend Rational Quot(const Rational&, const Rational&); // частно
};

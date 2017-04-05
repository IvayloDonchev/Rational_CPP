#pragma once
#include <iostream>
#include <cmath>
#include "DivideByZeroException.h"

class Rational
{
private:
	int num;			// ��������
	int den;			// ����������
	void Normalize();	// ��������� ������
public:
	static int gcd(int, int);		// �.�.�.
	Rational() : num(0), den(1) {}	// default constructor
	Rational(int, int);				// constructor
	Rational(double);				// ���������� Rational �� double 
	void Show() const;				// ������� �� ������
	bool IsZero() const;
	bool operator!() { return num == 0; }
	double ToDouble() const { return static_cast<double>(num) / den; }
	operator double() { return static_cast<double>(num) / den; }	// ����������� �� ��� double
	Rational operator+(const Rational&);
	Rational operator-(const Rational&);
	Rational operator*(const Rational&);
	Rational operator/(const Rational&);
	friend std::ostream& operator <<(std::ostream&, const Rational&);		// ����������� ���������� �� ���������
	friend std::istream& operator >>(std::istream&, Rational&);			// ����������� ���������� �� ���������
	Rational Sum(const Rational&);   // ���� � ����� �� �����
	Rational Sub(const Rational&);   // ������� � ����� �� �����
	Rational Mult(const Rational&);  // ������������ � ����� �� �����
	Rational Quot(const Rational&);  // ������ � ����� �� �����
	friend Rational Sum(const Rational&, const Rational&);  // ���� � ������ �-�
	friend Rational Sub(const Rational&, const Rational&);  // �������
	friend Rational Mult(const Rational&, const Rational&); // ������������
	friend Rational Quot(const Rational&, const Rational&); // ������
};

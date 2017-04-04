#include <iostream>
#include <cmath>
#include <exception>
using namespace std;

class Rational
{
private:
	int num;	// числител
	int den;    // знаменател
	void Normalize();
public:
	static int gcd(int, int);    // Н.О.Д.
	Rational() : num(0), den(1) {}
	Rational(int, int);
	Rational(double);
	void Show() const;
	bool IsZero() const;
	bool operator!() { return num == 0; }
	double ToDouble() const { return (double)num / den; }
	operator double() { return static_cast<double>(num) / den; }
	Rational operator+(const Rational&);
	Rational operator-(const Rational&);
	Rational operator*(const Rational&);
	Rational operator/(const Rational&);
	friend Rational operator +(const double&, const Rational&);
	friend ostream& operator <<(ostream&, const Rational&);
	friend istream& operator >>(istream&, Rational&);
	Rational Sum(const Rational&);   // сума с метод на класа
	Rational Sub(const Rational&);   // разлика с метод на класа
	Rational Mult(const Rational&);  // произведение с метод на класа
	Rational Quot(const Rational&);  // частно с метод на класа
	friend Rational Sum(const Rational&, const Rational&);  // сума с външна ф-я
	friend Rational Sub(const Rational&, const Rational&);  // разлика
	friend Rational Mult(const Rational&, const Rational&); // произведение
	friend Rational Quot(const Rational&, const Rational&); // частно
};

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
	if (b == 0) throw "Incorrect parameter...";
	else
		if(a == 0)
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
	cout << num << "/" << den << endl;
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
		throw "Division by zero!";
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

Rational operator+(const double &d, const Rational &r)
{
	return Rational(d+r);
}

ostream & operator<<(ostream &out, const Rational &r)
{
	out << r.num << "/" << r.den;
	return out;
}

istream & operator>>(istream &ent, Rational &r)
{
	cout << "numerator: "; ent >> r.num;
	cout << "denominator: "; ent >> r.den;
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

int main()
{
	cout << Rational::gcd(18, 12) << endl;   // 6
	try {
		Rational r1(2, 4);			// 1/2
		Rational r2(9, -12);			// -3/4
		cout << "r1 = "; r1.Show();
		cout << "r2 = "; r2.Show();
		Rational r;
		r = r1 + r2;
		cout << r << endl;
		(r1 + r2).Show();
		(r1*r2).Show();
		r = r1 - r2;
		r.Show();
		Sub(r1, r2).Show();
		r = r1 / r2;
		r.Show();
	}
	catch (char* s)
	{
		cerr << s << endl;
		return 0;
	}	
}



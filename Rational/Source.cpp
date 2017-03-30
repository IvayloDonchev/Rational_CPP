#include <iostream>
#include <cmath>
#include <exception>
using namespace std;

class Rational
{
private:
	int num;	// числител
	int den;    // знаменател
public:
	static int gcd(int, int);    // Н.О.Д.
	Rational() : num(0), den(1) {}
	Rational(int, int);
	void Show() const;
	bool IsZero() const;
	double ToDouble() const { return (double)num / den; }
	Rational Sum(const Rational&);   // сума с метод на класа
	Rational Sub(const Rational&);   // разлика с метод на класа
	Rational Mult(const Rational&);  // произведение с метод на класа
	Rational Quot(const Rational&);  // частно с метод на класа
	friend Rational Sum(const Rational&, const Rational&);  // сума с външна ф-я
	friend Rational Sub(const Rational&, const Rational&);  // разлика
	friend Rational Mult(const Rational&, const Rational&); // произведение
	friend Rational Quot(const Rational&, const Rational&); // частно
};

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
			int g = gcd(abs(a), abs(b));
			if (a > 0 && b > 0 || a < 0 && b < 0)
			{
				num = abs(a) / g;
				den = abs(b) / g;
			}
			else
			{
				num = -abs(a) / g;
				den = abs(b) / g;
			}
		}
}

void Rational::Show() const
{
	cout << num << "/" << den << endl;
}

bool Rational::IsZero() const
{
	return num == 0;
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
		r = Sum(r1, r2);
		r.Show();
		Sum(r1, r2);  r1.Show();
		Sum(r1, r2).Show();
		Mult(r1, r2).Show();
		Sub(r1, r2).Show();
		Quot(r1, r2).Show();
		Sum(Rational(1, 2), Rational(3, 4)).Show();
		
		r1.Sum(r2).Show();   // с метода на класа
		cout << r1.ToDouble() + 5 << endl;



	}
	catch (char* s)
	{
		cerr << s << endl;
		return 0;
	}	
}



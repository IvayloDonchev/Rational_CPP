#include "Rational.h"
using namespace std;

int main()
{
	cout << Rational::gcd(18, 12) << endl;   // 6
	try {
		Rational r1(2, 4);				
		Rational r2(9, -12);			
		cout << "r1 = "; r1.Show();		// r1 = 1/2
		cout << "r2 = " << r2 << endl;	// r2 = -3/4
		Rational r;
		r = r1 + r2;
		cout << r << endl;				// -1/4
		(r1 + r2).Show();				// -1/4
		cout << r1*r2 << endl;			// -3/8
		r = r1 - r2;					
		cout << r << endl;				// 5/4
		Sub(r1, r2).Show();				// 5/4
		r = r1 / r2;					
		r.Show();						// -2/3

		Rational r3 = 0.125;
		cout << "r3 = " << r3 << endl;  // r3 = 1/8
		cout << double(r3) + 0.25 << endl; // 0.375
		cout << r3 + Rational(0.25) << endl; // 3/8

		cout << r3 / Rational(0, 1) << endl; // Attempted to divide by zero
		// Rational r4(2, 0); // Incorrect parameter...

	}
	catch (DivideByZeroException &e)
	{
		cout << e.what() << endl;
		return 0;
	}
}



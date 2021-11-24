#pragma once

#include "Rational.h"
#include "TermList.h"
#include <vector>

class Poly
{
public:

	//constructors
	Poly(); //default constructor P(x) = 0
	Poly(Rational r); // P(x) = r
	Poly(int deg, Rational r); // P(x) = rx^deg
	Poly(const std::vector <Rational>& poly_vec);

	int deg() const;
	//distructors




private:
	TermList m_polynom;

	void init(int deg, Rational r);
};



// Required Operators: +, -, *
// ==, != checks if degree of Polynomials
//() receives singular Rational and returns the value of the polynomial at the place
//[] receives int, returns the coefficient of the term with the exponent equaling the int received
//<< printer dude (has to be global)

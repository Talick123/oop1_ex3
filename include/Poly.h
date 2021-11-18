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

};
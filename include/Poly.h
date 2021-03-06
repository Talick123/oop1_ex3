#pragma once

#include "Rational.h"
#include "TermList.h"
#include <vector>
#include <math.h>
#include <iostream>
#include "macros.h"

const Rational zero(DEFAULT_NUMER, DEFAULT_DENOMIN);
enum oprtr { MINUS, PLUS };

class Poly
{
public:

	//constructors
	Poly(); //default constructor P(x) = 0
	Poly(Rational r); // P(x) = r
	Poly(int deg, Rational r); // P(x) = rx^deg
	Poly(const std::vector <Rational>& poly_vec);

	//access operators
	Rational operator[](int exponent)const;
	Rational operator()(Rational input)const;

	//functions
	int deg() const;
	TermList getTermList()const;

	//operators
	Poly operator+=(const Poly& other);
	Poly operator-=(const Poly& other);
	Poly operator*=(const Poly& other);
	bool operator==(const Poly& other) const;



private:
	//members
	TermList m_polynom;

	//private functions
	std::vector <Rational> getVectorOfList()const;
	void mergeVectorsOfLists(std::vector <Rational> other_vec, int oprtr, std::vector <Rational>& new_vec)const;
	void multiply(const std::vector <Rational> other, std::vector <Rational>& new_vec);

	void init(int deg, Rational r);
};


//global operators
Poly operator+(const Poly& left, const Poly& right);
Poly operator-(const Poly& left, const Poly& right);
Poly operator*(const Poly& left, const Poly& right);
Poly operator*(const Rational& left, const Poly& right);
bool operator!=(const Poly& left, const Poly& right);
std::ostream& operator<<(std::ostream&, const Poly& poly);

// Required Operators: +, -, *
// ==, != checks if degree of Polynomials
//() receives singular Rational and returns the value of the polynomial at the place
//[] receives int, returns the coefficient of the term with the exponent equaling the int received
//<< printer dude (has to be global)

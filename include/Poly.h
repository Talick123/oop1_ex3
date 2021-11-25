#pragma once

#include "Rational.h"
#include "TermList.h"
#include <vector>
#include <math.h>
#include <iostream>

const Rational zero(0, 1);
enum oprtr { MINUS, PLUS };

class Poly
{
public:

	//constructors
	Poly(); //default constructor P(x) = 0
	Poly(Rational r); // P(x) = r
	Poly(int deg, Rational r); // P(x) = rx^deg
	Poly(const std::vector <Rational>& poly_vec);

	Rational operator[](int exponent)const;
	Rational operator()(Rational input)const;

	int deg() const;
	TermList getTermList()const;

	//destructors


	//operators
	Poly operator+=(const Poly& other);
	Poly operator-=(const Poly& other);
	Poly operator*=(const Poly& other);
	bool operator==(const Poly& other) const;



private:
	TermList m_polynom;

	//TermList getTermList()const;
	std::vector <Rational> getVectorOfList()const;
	void mergeVectorsOfLists(std::vector <Rational> other_vec, int oprtr, std::vector <Rational>& new_vec)const;
	//std::vector <Rational> mergeVectorsOfLists(std::vector <Rational>& other_vec, int oprtr)const;
	void multiply(const std::vector <Rational> other, std::vector <Rational>& new_vec);

	void init(int deg, Rational r);
};



Poly operator+(const Poly& left, const Poly& right);
Poly operator-(const Poly& left, const Poly& right);
Poly operator*(const Poly& left, const Poly& right);
bool operator!=(const Poly& left, const Poly& right);
std::ostream& operator<<(std::ostream&, const Poly& poly);

// Required Operators: +, -, *
// ==, != checks if degree of Polynomials
//() receives singular Rational and returns the value of the polynomial at the place
//[] receives int, returns the coefficient of the term with the exponent equaling the int received
//<< printer dude (has to be global)

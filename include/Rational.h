#pragma once


const int DEFAULT_NUMER = 0;
const int DEFAULT_DENOMIN = 1;

// I M P O R T A N T ! 
// do not divide by 0 

class Rational
{
public:
	//constructors
	Rational(int numer, int denomin) : m_numerator(DEFAULT_NUMER), m_denominator(DEFAULT_DENOMIN) {};
	
	Rational operator+(const Rational& other);
	Rational operator-(const Rational& other);
	Rational operator*(const Rational& other);
	Rational operator/(const Rational& other);

	
	//distructors


private:
	void simplify_rational(int numer, int denomin);

	int m_numerator; //signed
	int m_denominator;
}

//Operators:
Rational operator+=(const Rational& left, const Rational& right);
Rational operator-=(const Rational& left, const Rational& right);


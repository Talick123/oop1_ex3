#pragma once

#include <numeric>
#include <iosfwd>
#include <iostream>
#include "macros.h"

class Rational
{
public:
	//constructors
	Rational(); //default constructor
	Rational(int numer, int denomin);
	Rational(const Rational& copy); //copy constructor

	void set(const int numer, const int denomin);

	//access funcitions
	int getNumer()const;
	int getDenomin()const;

	//Operators
	Rational &operator+=(const Rational& other);
	Rational &operator-=(const Rational& other);
	Rational &operator*=(const Rational& other);
	Rational &operator/=(const Rational& other);
	bool operator==(const Rational& other) const;
	bool operator<(const Rational& other) const;
	Rational &operator+();
	Rational &operator-();

private:
	void simplify();

	int m_numerator;
	int m_denominator;
};

//Operators:
Rational operator+(const Rational& left, const Rational& right);
Rational operator-(const Rational& left, const Rational& right);
Rational operator*(const Rational& left, const Rational& right);
Rational operator/(const Rational& left, const Rational& right);
bool operator!=(const Rational& left, const Rational& right);
bool operator>(const Rational& left, const Rational& right);
bool operator<=(const Rational& left, const Rational& right);
bool operator>=(const Rational& left, const Rational& right);
std::ostream& operator<<(std::ostream&, const Rational& rtnl);

int getNewDenomin(int old_denomin, int other_denomin);
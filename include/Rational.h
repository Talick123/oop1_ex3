#pragma once

#include <numeric>
#include <iosfwd>
#include <iostream>


const int DEFAULT_NUMER = 0;
const int DEFAULT_DENOMIN = 1;

// I M P O R T A N T ! 
// do not divide by 0 

class Rational
{
public:
	//constructors
	Rational(); //default constructor
	Rational(int numer, int denomin);
	Rational(const Rational& copy); //copy constructor

	void set(const int numer, const int denomin);
	int getNumer()const;
	int getDenomin()const;

	Rational &operator+=(const Rational& other);
	Rational &operator-=(const Rational& other);
	Rational &operator*=(const Rational& other);
	Rational &operator/=(const Rational& other);
	bool operator==(const Rational& other) const;
	bool operator<(const Rational& other) const;
	Rational &operator+();
	Rational &operator-();


	//destructors

private:
	void simplify();


	int m_numerator; //signed
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
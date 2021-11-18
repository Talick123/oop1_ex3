#include "Rational.h"


Rational::Rational(int numer, int denomin) : m_numerator(DEFAULT_NUMER), m_denominator(DEFAULT_DENOMIN) 
{
	if (denomin == 0)
		return;
	
	m_denominator = denomin;
	m_numerator = numer;

	simplify();
};

void Rational::simplify()
{
	if (m_numerator == DEFAULT_NUMER)
	{
		m_denominator = DEFAULT_DENOMIN;
		return;
	}

	int gcd = std::gcd(m_numerator, m_denominator);

	m_numerator /= gcd;
	m_denominator /= gcd;

	if (m_denominator < 0)
	{
		m_numerator *= -1;
		m_denominator *= -1;
	}
}


int Rational::getNumer()const
{
	return m_numerator;
}
int Rational::getDenomin()const
{
	return m_denominator;
}

Rational Rational::operator+=(const Rational& other)
{
	int new_denomin = m_denominator;

	if (m_denominator != other.getDenomin())
		new_denomin = std::lcm(m_denominator, other.getDenomin());

	m_numerator = (m_numerator * (new_denomin/m_denominator) + other.getNumer() * (new_denomin/other.getDenomin()));
	m_denominator = new_denomin;
	simplify();
	return *this;
}



Rational Rational::operator-=(const Rational& other)
{

}
Rational Rational::operator*=(const Rational& other)
{

}
Rational Rational::operator/=(const Rational& other)
{

}
bool Rational::operator==(const Rational& other)
{

}
bool Rational::operator<(const Rational& other)
{

}



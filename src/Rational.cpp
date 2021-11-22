#include "Rational.h"


//=============================================================================

//Constructor
Rational::Rational(int numer, int denomin) : m_numerator(DEFAULT_NUMER), m_denominator(DEFAULT_DENOMIN) 
{
	if (denomin == 0)
		return;
	
	m_denominator = denomin;
	m_numerator = numer;

	simplify();
}

//=============================================================================

//Function simplifies fraction
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

//=============================================================================


int Rational::getNumer()const
{
	return m_numerator;
}

//=============================================================================


int Rational::getDenomin()const
{
	return m_denominator;
}

//=============================================================================


Rational &Rational::operator+=(const Rational& other)
{
	int new_denomin = getNewDenomin(m_denominator, other.getDenomin());

	m_numerator = (m_numerator * (new_denomin/m_denominator) + other.getNumer() * (new_denomin/other.getDenomin()));
	m_denominator = new_denomin;
	simplify();
	return *this;
}

//=============================================================================


Rational &Rational::operator-=(const Rational& other)
{
	int new_denomin = getNewDenomin(m_denominator, other.getDenomin());

	m_numerator = (m_numerator * (new_denomin / m_denominator) - other.getNumer() * (new_denomin / other.getDenomin()));
	m_denominator = new_denomin;
	simplify();
	return *this;
}

//=============================================================================

Rational &Rational::operator*=(const Rational& other)
{
	m_numerator *= other.getNumer();
	m_denominator *= other.getDenomin();

	simplify();
	return *this;
}

//=============================================================================

Rational &Rational::operator/=(const Rational& other)
{
	m_numerator *= other.getDenomin();
	m_denominator *= other.getNumer();

	simplify();
	return *this;
}

//=============================================================================

bool Rational::operator==(const Rational& other) const
{
	return (m_numerator == other.getNumer()) && (m_denominator == other.getDenomin());
}

//=============================================================================

//should i turn into same denominator and compare numerators? might be more accurate??
bool Rational::operator<(const Rational& other) const
{
	double val1, val2;
	val1 = (double)m_numerator / m_denominator;
	val2 = (double)other.getNumer() / other.getDenomin();
	
	if (std::abs(val1 - val2) < 0.5)
		return true;
	return false;
}

//=============================================================================
Rational &Rational::operator+()
{
	return *this;
}
//=============================================================================

Rational& Rational::operator-()
{
	m_numerator *= -1;
	return *this;
}
//=============================================================================

Rational operator+(const Rational& left, const Rational& right)
{
	Rational newRat(left.getNumer(), left.getDenomin());
	return newRat += right;
}

//=============================================================================

Rational operator-(const Rational& left, const Rational& right)
{
	Rational newRat(left.getNumer(), left.getDenomin());
	return newRat -= right;
}

//=============================================================================

Rational operator*(const Rational& left, const Rational& right)
{
	Rational newRat(left.getNumer(), left.getDenomin());
	return newRat *= right;
}

//=============================================================================

Rational operator/(const Rational& left, const Rational& right)
{
	Rational newRat(left.getNumer(), left.getDenomin());
	return newRat /= right;
}

//=============================================================================

bool operator!=(const Rational& left, const Rational& right)
{
	return !(left == right);
}

//=============================================================================

bool operator>(const Rational& left, const Rational& right)
{
	return !(left < right);
}

//=============================================================================

bool operator<=(const Rational& left, const Rational& right)
{
	return (left < right) || (left == right);
}

//=============================================================================

bool operator>=(const Rational& left, const Rational& right)
{
	return (left > right) || (left == right);
}

//=============================================================================
std::ostream& operator<<(std::ostream&, const Rational& rtnl)
{
	return std::cout << rtnl.getNumer() << '/' << rtnl.getDenomin();
}

//=============================================================================

int getNewDenomin(int old_denomin, int other_denomin)
{
	int new_denomin = old_denomin;

	if (old_denomin != other_denomin)
		new_denomin = std::lcm(old_denomin, other_denomin);

	return new_denomin;
}



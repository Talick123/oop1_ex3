#include "Rational.h"


//=============================================================================	

//Default Constructor
Rational::Rational() : m_numerator(DEFAULT_NUMER), m_denominator(DEFAULT_DENOMIN) {}

//-----------------------------------------------------


//Constructor
Rational::Rational(int numer, int denomin) : m_numerator(DEFAULT_NUMER), m_denominator(DEFAULT_DENOMIN) 
{
	if (denomin == 0)
		return;
	
	m_denominator = denomin;
	m_numerator = numer;

	simplify();
}

//-----------------------------------------------------

//Copy Constructor
Rational::Rational(const Rational& copy) 
	:m_numerator(copy.getNumer()), m_denominator(copy.getDenomin())
{}



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

bool Rational::operator<(const Rational& other) const
{
	int new_denomin = getNewDenomin(m_denominator, other.getDenomin());
	int temp_numer = m_numerator * (new_denomin / m_denominator);
	return (temp_numer <  (other.getNumer() * (new_denomin / other.getDenomin())));
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
	Rational newRat(left);
	return newRat += right;
}

//=============================================================================

Rational operator-(const Rational& left, const Rational& right)
{
	Rational newRat(left);
	return newRat -= right;
}

//=============================================================================

Rational operator*(const Rational& left, const Rational& right)
{
	Rational newRat(left);
	return newRat *= right;
}

//=============================================================================

Rational operator/(const Rational& left, const Rational& right)
{
	Rational newRat(left);
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


void Rational::set(const int numer, const int denomin)
{
	m_numerator = numer;
	m_denominator = denomin;
	simplify();
}
#include "Poly.h"


Poly::Poly() : m_polynom()
{
	Rational r = Rational(0, 1);
	init(0, r);
}


Poly::Poly(Rational r) :m_polynom()
{
	init(0, r);
}


Poly::Poly(int deg, Rational r) : m_polynom()
{
	init(deg, r);
}


Poly::Poly(const std::vector <Rational>& poly_vec) :m_polynom()
{
	m_polynom = TermList(poly_vec);
}


void Poly::init(int deg, Rational r)
{
	std::vector<Rational> poly_vec(deg, Rational(0,1)); 
	poly_vec[deg] = r;
	m_polynom = TermList(poly_vec);
}


int Poly::deg()const
{
	return m_polynom.getTermListHead()->_exponent;
}

//function receives exponent and returns coefficent of the term in the list with that exponent
Rational Poly::operator[](int exponent)
{
	if (exponent < 0 || exponent > deg()) //checks that exponent received is valid
	{
		std::cout << "Error! Index " << exponent << " out of range.";
		return zero;
	}

	auto temp(m_polynom); //defining iterator using copy constructor
	
	if (temp[exponent] == NULL) //if not found in list
		return zero;

	return temp[exponent]->_coeffic;
}
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

//TODO: change this 
int Poly::deg()const
{
	return 1;
}
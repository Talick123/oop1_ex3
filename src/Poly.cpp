#include "Poly.h"


Poly::Poly() : m_polynom()
{
	init(0, Rational(0, 1));
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


Poly::init(int deg, Rational r)
{
	vector<Term> poly_vec(1);
	poly_vec[0] = { 1, r, nullptr };
	m_polynom = TermList(poly_vec);
}


int Poly::deg()const
{

}
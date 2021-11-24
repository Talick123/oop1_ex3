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
	std::vector<Rational> poly_vec(deg, Rational(0, 1));
	poly_vec[deg] = r;
	m_polynom = TermList(poly_vec);
}

//TODO: change this 
int Poly::deg()const
{
	return 1;
}


TermList Poly::getTermList()const
{
	return  m_polynom;
}

std::vector <Rational>& Poly::getVectorOfList()const
{	
	return m_polynom.getVector();
}

/////////////////////////
Poly Poly::operator+=(const Poly& other)
{
	//get vector of current poly and the vector of other and
	//std::vector <Rational>& poly_vec  = getVectorOfList();

	/*TermList new_tl = TermList(other.getVectorOfList());*/

	std::vector <Rational>  new_vec(other.deg(), Rational(0, 1));
	new_vec = mergeVectorsOfLists(other.getVectorOfList());
	Poly new_poly = Poly(new_vec);
	m_polynom = new_poly.getTermList();

	return *this;
}

Poly Poly::operator-=(const Poly& other)
{
	return *this;
}

Poly Poly::operator*=(const Poly& other)
{
	return *this;
}


std::vector <Rational>& Poly::mergeVectorsOfLists(std::vector <Rational>& other_vec)const
{
	//vector size of the biggest one 
	int merged_vec_size =( (deg() > other_vec.size()) ? int(deg()) : int(other_vec.size()));
	std::vector <Rational> merged_vec(merged_vec_size, Rational(0,1));
	std::vector <Rational> current_vec(deg(), Rational(0,1));
	
	current_vec = getVectorOfList();

	//loop on both - TODO: can change the if to one
	for (int i = 0; i < merged_vec_size; i++)
	{
		//if one of them is smaller
		if (i >= current_vec.size())
		{
			merged_vec[i] = other_vec[i];
			break;
		}
		else if (i >= other_vec.size())
		{
			merged_vec[i] = current_vec[i];
			break;
		}
		merged_vec[i] = current_vec[i] + other_vec[i];
	}
	return merged_vec;
}



//if (i >= current_vec.size())
//{
//	//push the rest from other_vec
//	for (i; i < merged_vec_size; i++)
//	{
//		merged_vec[i] =  other_vec[i];
//	}
//	break;
//}
//else if (i >= other_vec.size())
//{
//	//push the rest from current_vec
//	for (i; i < merged_vec_size; i++)
//	{
//		merged_vec[i] = current_vec[i];
//	}
//}
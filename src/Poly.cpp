#include "Poly.h"


Poly::Poly() : m_polynom()
{
	Rational r = Rational(0, 1);
	init(0, r);
}

//-----------------------------------------------------

Poly::Poly(Rational r) :m_polynom()
{
	init(0, r);
}

//-----------------------------------------------------

Poly::Poly(int deg, Rational r) : m_polynom()
{
	init(deg, r);
}

//-----------------------------------------------------

Poly::Poly(const std::vector <Rational>& poly_vec) :m_polynom()
{
	m_polynom = TermList(poly_vec);
}

//-----------------------------------------------------

void Poly::init(int deg, Rational r)
{
	std::vector<Rational> poly_vec(deg, Rational(0, 1));
	poly_vec[deg] = r;
	m_polynom = TermList(poly_vec);
}

//-----------------------------------------------------

int Poly::deg()const
{
	return m_polynom.getTermListHead()->_exponent;
}

//-----------------------------------------------------

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


//-----------------------------------------------------

TermList Poly::getTermList()const
{
	return  m_polynom;
}

//-----------------------------------------------------

std::vector <Rational>& Poly::getVectorOfList()const
{
	return m_polynom.getVector();
}

//========================= O P E R A T O R ====================

Poly Poly::operator+=(const Poly& other)
{
	//get vector of current poly and the vector of other and
	//std::vector <Rational>& poly_vec  = getVectorOfList();

	/*TermList new_tl = TermList(other.getVectorOfList());*/

	std::vector <Rational>  new_vec(other.deg(), Rational(0, 1));
	new_vec = mergeVectorsOfLists(other.getVectorOfList(), PLUS);
	Poly new_poly = Poly(new_vec);
	m_polynom = new_poly.getTermList();

	return *this;
}

//-----------------------------------------------------

Poly Poly::operator-=(const Poly& other)
{
	std::vector <Rational>  new_vec(other.deg(), Rational(0, 1));
	new_vec = mergeVectorsOfLists(other.getVectorOfList(), MINUS);
	Poly new_poly = Poly(new_vec);
	m_polynom = new_poly.getTermList();

	return *this;
}

// -----------------------------------------------

Poly Poly::operator*=(const Poly& other)
{
	return *this + other;
}

// -----------------------------------------------

bool Poly::operator==(const Poly& other) const
{
	return (deg() == other.deg());
}

// -----------------------------------------------

std::vector <Rational>& Poly::mergeVectorsOfLists(std::vector <Rational>& other_vec, int oprtr)const
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
		if (current_vec[i] == Rational(0, 1) && other_vec[i] == Rational(0, 1)) continue;
		merged_vec[i] = (oprtr == PLUS) ? (current_vec[i] + other_vec[i]) : (current_vec[i] + other_vec[i]);
	}
	return merged_vec;
}

//-----------------------------------------------------
//TODO: check later
Poly operator+(const Poly& left, const Poly& right)
{
	Poly new_poly(left);
	return new_poly += right;
}

//-----------------------------------------------------

Poly operator-(const Poly& left, const Poly& right)
{
	Poly new_poly(left);
	return new_poly -= right;
}

//-----------------------------------------------------

Poly operator*(const Poly& left, const Poly& right)
{
	Poly new_poly(left);
	return new_poly *= right;
}

//-----------------------------------------------------

bool operator!=(const Poly & left, const Poly & right)
{
	return !(left == right);
}

//-----------------------------------------------------

std::ostream& operator<<(std::ostream& ostream, const Poly& right)
{
	Term* head = right.getTermList().getTermListHead();
	
	if (!head || (head->_coeffic == Rational(0, 1) && head->_exponent == 0)) 
		return std::cout << "0" << std::endl;
	
	head->_coeffic < Rational(0, 1) ? "-" : "";
	while (head)
	{
		std::cout << head->_coeffic << "*X";
		head->_exponent != 0 ? std::cout << "^" : std::cout << "";
		std::cout << head->_exponent;

		head = head->_next;

		head ? (head->_coeffic < Rational(0, 1) ? std::cout << "-" : std::cout << "+") : std::cout << std::endl;
	}
	
	return ostream;
}
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
	std::vector<Rational> poly_vec(deg + 1, Rational(0, 1));
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
Rational Poly::operator[](int exponent)const
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

	std::vector <Rational>  new_vec((other.deg() + 1), Rational(0, 1));
	new_vec = mergeVectorsOfLists(other.getVectorOfList(), PLUS);
	Poly new_poly = Poly(new_vec);
	m_polynom = new_poly.getTermList();

	return *this;
}

//-----------------------------------------------------

Poly Poly::operator-=(const Poly& other)
{
	std::vector <Rational>  new_vec((other.deg() + 1), Rational(0, 1));
	new_vec = mergeVectorsOfLists(other.getVectorOfList(), MINUS);
	Poly new_poly = Poly(new_vec);
	m_polynom = new_poly.getTermList();

	return *this;
}

// -----------------------------------------------

Poly Poly::operator*=(const Poly& other)
{
	std::vector <Rational>  new_vec(other.deg() + 1, Rational(0, 1));
	new_vec = multiply(other.getVectorOfList());
	Poly new_poly = Poly(new_vec);
	m_polynom = new_poly.getTermList();
	return *this + other;
}

// -----------------------------------------------

bool Poly::operator==(const Poly& other) const
{
	return (deg() == other.deg());
}

// ----------------------------------------------

std::vector <Rational> Poly::multiply(const std::vector <Rational> other)
{
	int l_size = (int)other.size(), r_size = int(getVectorOfList().size());
	std::vector <Rational> new_vec((l_size + r_size) - 1);
	std::vector <Rational> curr_vec(r_size + 1);
	curr_vec = getVectorOfList();

	// Initialize the product polynomial
	for (int i = 0; i < l_size + r_size - 1; i++)
		new_vec[i] = Rational();

	// Multiply two polynomials term by term

	// Take ever term of first polynomial
	for (int i = 0; i < l_size; i++)
	{
		// Multiply the current term of first polynomial
		// with every term of second polynomial.
		for (int j = 0; j < r_size; j++)
			new_vec[(i + j)] += curr_vec[i] * other[j];
	}

	return new_vec;
}

// -----------------------------------------------

std::vector <Rational>& Poly::mergeVectorsOfLists(std::vector <Rational>& other_vec, int oprtr)const
{
	//vector size of the biggest one
	int merged_vec_size =( (deg() > other_vec.size()) ? int(deg()) : int(other_vec.size()));
	std::vector <Rational> merged_vec(merged_vec_size + 1, Rational(0,1));
	std::vector <Rational> current_vec(deg() + 1, Rational(0,1));

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

	//head->_coeffic < Rational(0, 1) ? "-" : "";
	while (head)
	{
		std::cout << head->_coeffic << "*X";
		head->_exponent != 0 ? std::cout << "^" : std::cout << "";
		std::cout << head->_exponent;

		head = head->_next;

		head ? (head->_coeffic < Rational(0, 1) ? std::cout << "" : std::cout << "+") : std::cout << std::endl;
	}

	return ostream;
}

//-----------------------------------------------------

Rational Poly::operator()(Rational input)const
{
	Term* temp = m_polynom.getTermListHead();
	Rational final, temp_input;
	int numer, denomin;

	while (temp != NULL)
	{
		if (!(temp->_coeffic.getNumer() == 0 && temp->_exponent == 0))
		{
			numer = (int)pow(input.getNumer(), temp->_exponent);
			denomin = (int)pow(input.getDenomin(), temp->_exponent);

			temp_input.set(numer, denomin);
			temp_input *= temp->_coeffic;
			final += temp_input;
		}

		temp = temp->_next;
	}

	return final;
}




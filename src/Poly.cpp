#include "Poly.h"

//================= constructors=====================

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

Poly::Poly(const std::vector <Rational>& poly_vec) :m_polynom(poly_vec)
{
	/*std::cout << poly_vec[0];
	m_polynom = TermList(poly_vec);*/
}


//======================== functions =======================

void Poly::init(int deg, Rational r)
{
	int n = deg + 1;
	std::vector<Rational> poly_vec(n, Rational(0, 1));
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

std::vector <Rational> Poly::getVectorOfList()const
{
	return m_polynom.getVector();
}

//========================= O P E R A T O R S ====================

Poly Poly::operator+=(const Poly& other)
{
	int n = (other.deg() + 1);
	std::vector <Rational>  new_vec(n);
	mergeVectorsOfLists(other.getVectorOfList(), PLUS, new_vec);
	*this = Poly(new_vec);

	return *this;
}

//-----------------------------------------------------

Poly Poly::operator-=(const Poly& other)
{
	int n = (other.deg() + 1);
	std::vector <Rational>  new_vec(n);
	mergeVectorsOfLists(other.getVectorOfList(), MINUS, new_vec);
	*this = Poly(new_vec);

	return *this;
}

// -----------------------------------------------

Poly Poly::operator*=(const Poly& other)
{
	int n = other.deg() + 1;
	std::vector <Rational>  new_vec((n > other.getVectorOfList().size()) ? n : int(other.getVectorOfList().size()));
	std::vector <Rational> other_vec(other.deg());
	other_vec = other.getVectorOfList();
	multiply(other_vec, new_vec);
	Poly new_poly = Poly(new_vec);
	m_polynom = new_poly.getTermList();
	return *this;
}

// -----------------------------------------------

bool Poly::operator==(const Poly& other) const
{
	return (deg() == other.deg());
}

// ----------------------------------------------

void Poly::multiply(const std::vector <Rational> other, std::vector <Rational>& new_vec)
{
	int exponent = 0;
	std::vector <Rational> curr_vec = getVectorOfList();
	int l_size = (int)other.size(), r_size = int(curr_vec.size()),
		total_size = (l_size + r_size) - 1;
	std::vector <Rational> new_vec_tmp(total_size);

	// Initialize the product polynomial
	for (int i = 0; i < total_size; i++)
		new_vec_tmp[i] = Rational();

	// Multiply two polynomials term by term
	// Take ever term of first polynomial
	for (int i = 0; i < r_size; i++)
	{
		// Multiply the current term of first polynomial
		// with every term of second polynomial.
		for (int j = 0; j < l_size; j++)
		{
			exponent = i + j;
			new_vec_tmp[exponent] += curr_vec[i] * other[j];
		}
	}
	new_vec = new_vec_tmp;
}

// -----------------------------------------------

//std::vector <Rational> Poly::mergeVectorsOfLists(std::vector <Rational>& other_vec, int oprtr)const
void Poly::mergeVectorsOfLists(std::vector <Rational> other_vec, int oprtr, std::vector <Rational>& new_vec)const
{
	int n = deg();
	//vector size of the biggest one
	int merged_vec_size = ((n > other_vec.size()) ? n : int(other_vec.size()));
	std::vector <Rational> merged_vec(++merged_vec_size);
	std::vector <Rational> current_vec(++n);

	current_vec = getVectorOfList();

	//loop on both - TODO: can change the if to one
	for (int i = 0; i < merged_vec_size - 1; i++)
	{
		//if one of them is smaller
		if (i >= current_vec.size())
		{
			merged_vec[i] = other_vec[i];
			continue;
		}
		else if (i >= other_vec.size())
		{
			merged_vec[i] = current_vec[i];
			continue;
		}
		if (current_vec[i] == Rational(0, 1) && other_vec[i] == Rational(0, 1)) continue;

		merged_vec[i] = (oprtr == PLUS) ? (current_vec[i] + other_vec[i]) : (current_vec[i] - other_vec[i]);
	}
	new_vec = merged_vec;
}

//-----------------------------------------------------

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

Poly operator*(const Rational& left, const Poly& right)
{
	return Poly(left) * right;
}

//-----------------------------------------------------

bool operator!=(const Poly & left, const Poly & right)
{
	return !(left == right);
}

//-----------------------------------------------------

std::ostream& operator<<(std::ostream& ostream, const Poly& right)
{
	auto head1 = right.getTermList();
	auto head = head1.getTermListHead();

	/*std::cout << head->_coeffic;
	std::cout << " " << head->_exponent << "\n";*/
	if (!head || ((head->_coeffic == zero) && (head->_exponent == 0)))
		return std::cout << "0" << std::endl;

	while (head)
	{
		std::cout << head->_coeffic;
		head->_exponent != 0 ? std::cout << "*X^" << head->_exponent : std::cout << "";
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

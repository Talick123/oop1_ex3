#include "TermList.h"


TermList::TermList() : m_termList(nullptr) { }


TermList::TermList(const std::vector <Rational>& poly_vec) : m_termList(nullptr)
{
	struct Term *new_list = nullptr;

	new_list = buildListTerm(poly_vec);
	m_termList = new_list;
}

//copy constructor
TermList::TermList(const TermList& tl)
{
	//m_termList = tl.m_termList; //get term list head ?
	m_termList = tl.getTermListHead();
}

TermList::~TermList()
{
	freeList();
}

Term* TermList::buildListTerm(const std::vector <Rational>& poly_vec)
{
	Term* head = NULL;
	int size = int(poly_vec.size()),
		curr = 0;

	while (curr < size)
	{
		if (poly_vec[curr].getDenomin() == 1 && poly_vec[curr].getNumer() == 0) continue;

		Term* tmp = newTerm(poly_vec[curr], curr );

		tmp->_next = head;
		head = tmp;
		curr++;
	}
	return head;
}

Term* TermList::newTerm(Rational r, int exponent)
{
	Term* term = new (std::nothrow) Term({ 0,Rational(0,1),NULL });
	if (!term)
	{
		std::cerr << "Error in allocation" << std::endl;
		exit(EXIT_FAILURE);
	}

	term->_coeffic = r;
	term->_exponent = exponent;
	term->_next = NULL;
	return term;
}

void TermList::freeList()
{
	Term *tmp, *head = m_termList;
	while (head != NULL)
	{
		tmp = head->_next;
		delete head;
		head = tmp;
	}
}

Term* TermList::getTermListHead()const
{
	return m_termList; //return head to term list
}

std::vector <Rational>& TermList::getVector()const
{
	int index = m_termList->_exponent; //also size of vec
	std::vector <Rational> list_vec(index + 1, Rational(0, 1));
	Term* head = m_termList;
	while (head)
	{
		if (head->_exponent != index) continue;
		list_vec[index] = head->_coeffic;
		index--;
	}
	return list_vec;
}

//function receives exponent and returns pointer to term in list with that exponent
Term* TermList::operator[](int exponent) const
{
	Term* temp = m_termList; //iterator

	while (temp != NULL)
	{
		if (temp->_exponent == exponent) //if exponent found
			return temp;
		else
			temp = temp->_next;
	}

	return temp;
}

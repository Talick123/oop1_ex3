#include "TermList.h"


TermList::TermList() : m_termList(nullptr)
{
	
}


TermList::TermList(const std::vector <Rational>& poly_vec) : m_termList(nullptr)
{
	struct Term *new_list = nullptr;
	
	new_list = buildListTerm(poly_vec);
	m_termList = new_list;
}

TermList::~TermList()
{
	freeList();
}

Term* TermList::buildListTerm(const std::vector <Rational>& poly_vec)
{
	Term* head = NULL, * last = NULL;
	int size = poly_vec.size(), 
		curr = 0;
	 
	while (curr < size)
	{
		if (poly_vec[curr] == Rational(0,0)) continue;

		Term* tmp = new_term(poly_vec[curr], curr );

		tmp->_next = head;
		head = tmp;
		curr++;
	}

	return head;
}

Term* TermList::new_term(Rational r, int exponent)
{
	Term* term = new (std::nothrow) Term({ 0,Rational(0,0),NULL });
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
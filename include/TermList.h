#pragma once

#include "Term.h"
#include "Rational.h"

#include <numeric>
#include <iosfwd>
#include <iostream>
#include <vector>


class TermList
{
public:
	//constructors
	TermList();
	TermList(const std::vector <Rational>& poly_vec);


	//distructors
	~TermList(); //delete list


private:
	Term* m_termList;

	Term* buildListTerm(const std::vector <Rational>& poly_vec);
	Term* new_term(Rational r, int exponent);
};
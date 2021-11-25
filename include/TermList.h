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
	TermList(const TermList& tl); //copy constructor ?
	//destructors
	~TermList(); //free list

	//access function
	Term* getTermListHead()const;
	std::vector <Rational> getVector()const;
	//operators
	Term* operator[](int exponent)const;

private:
	//members
	Term* m_termList;

	//private functions
	Term* buildListTerm(const std::vector <Rational>& poly_vec);
	Term* newTerm(Rational r, int exponent);
	void freeList();
};
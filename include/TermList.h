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

	Term* getTermListHead()const;

	Term* operator[](int exponent)const;


private:
	Term* m_termList;

	Term* buildListTerm(const std::vector <Rational>& poly_vec);
	Term* newTerm(Rational r, int exponent);
	void freeList();

};

//Require Functions for Poly's Use
/*

//////////////////////////////////////////////////////////////////////////////////////////////
- function that receives vector of rationals and adds to current list
- copy constructor- p3 = p1 + p2 => copy p1 to p3 and add p2 vector to the function above

OR :
- p3 = p1 + p2 => get vector from p1 and add the vector of p2 and then build with it new Poly
//////////////////////////////////////////////////////////////////////////////////////////////
-

*/

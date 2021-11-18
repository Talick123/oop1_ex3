#pragma once

#include "Rational.h"

struct Term
{
	int _exponent;
	Rational _coeffic;
	Term *_next;
};
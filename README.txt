OOP ex3 - Implementation of Rational numbers and Polynomials

Written by: Tali Kalev (טלי כלב), ID:208629691
            Noga Levy (נוגה לוי), ID:315260927

General Description of the Assignment:
  In this assignment, we were requested to implement classes and functions that
  allow representation and manipulation of polynomials and Rationals numbers.

Design:
  Classes: Poly, List, Rational
    Rational:
    - deals with the construction and representation of rational numbers in Polynomials (the coefficient)
    - contains functions used for mathematical operations
   TermList:
   - deals with the memory allocation for a list of 'Term' structures
   - contains functions used for memory allocation and release
   Poly:
   - deals with the mathematical operations of polynomials represented as a list of structures

 Structures: Term
   Term:
   - structure containing an exponential value, variable of type Rational and pointer to next structure


Files:
  Poly.h and Poly.cpp
    - files containing the Poly class and global functions used to manipulate variables of type Poly
  TermList.h and TermList.cpp
    - files containing the TermList class and global functions used to add, remove or manipulate variables of type TermList
  Rational.h and Rational.cpp
    - files containing the Rational class and global functions used for mathematical operations and simplifications of variables of type Rational
  Term.h
    - file containing struct Term that represents the exponential value and the coefficient (Rational) of a term in a polynomial (as well as pointer to next struct)

Main Data Structures and their Jobs:
	- see Design above

Notable Algorithms:
	- for multiplying polynomials we used the following algorithm: https://www.geeksforgeeks.org/multiply-two-polynomials-2/

Known Bugs:
	- there are no known bugs in the program

Other General Notes:
	- none

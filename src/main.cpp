#include "Poly.h"

#include <string>
/*
Poly read_poly()
{
    int deg, numer, denomin;
    Rational coeffic;
    std::cout << "Enter the degree of the Polygon: ";
    std::cin >> deg;
    int size = deg + 1;
    std::vector<Rational> poly_vec(size);

    while (deg >= 0)
    {
        std::cout << "Enter the numerator of the coefficient of the term with the exponent " << deg << ": ";
        std::cin >> numer;
        std::cout << "\n";
        std::cout << "Enter the denominator of the coefficient of the term with the exponent " << deg << ": ";
        std::cin >> denomin;
        std::cout << "\n";
        coeffic.set(numer, denomin);
        poly_vec[deg] = coeffic;
        --deg;
    }

   return Poly(poly_vec);
}
*/


int main()
{
    //Poly P1 = read_poly();
    //Poly P2 = read_poly();
    auto c1 = std::vector<Rational>{ Rational(2,1), Rational(17,2) };
    auto c2 = std::vector<Rational>{ Rational(3,1), Rational(2,2) };
    auto P1 = Poly(c1);
    auto P2 = Poly(c2);

    std::cout << P1.getTermList().getTermListHead()->_coeffic;
    //testing operator<<
    std::cout << "P1 is: " << P1 << '\n';
    std::cout << "P2 is: " << P2 << '\n';

    //testing operators + and -
    std::cout << "P1+P2 is: " << P1+P2 << '\n';
    std::cout << "P1-P2 is: " << P1 - P2 << '\n';

    //testing operator*
    std::cout << "P1*P2 is: " << P1 * P2 << std::endl;

    //testing operator==
    std::string isEqual = (P1 == P2) ? "equal" : "not equal";
    std::cout << "P1 and B are " << isEqual << '\n';
    
    //testing operator[]
    int exponent;
    std::cout << "Enter the exponent of a term: ";
    std::cin >> exponent;
    std::cout << "\n";
    std::cout << "The cofficient of the term with an exponent " << exponent << " in P1 is : " << P1[exponent] << '\n';
    
    //testing operator()
    int numer, denomin;
    std::cout << "Enter the numerator of the number you would like to insert into P1: ";
    std::cin >> numer;
    std::cout << "\n";
    std::cout << "Enter the denominator of the number you would like to insert into P1: ";
    std::cin >> denomin;
    std::cout << "\n";
    Rational rat(numer, denomin);
    std::cout << "The x = " << rat << " the P1 is equal to: " << P1(rat) << "\n";

    //===========================================================

    Rational A(3, 4), B(-1, 4);

    std::cout << "A is: " << A << '\n';
    std::cout << "B is: " << B << '\n';
    std::cout << "A is: " << (A < B ? "lesser" : "greater") << " than B" << '\n';
    std::cout << "A+B is: " << A + B << '\n';
    std::cout << "A-B is: " << A - B << '\n';
    std::cout << "A*B is: " << A * B << '\n';
    std::cout << "A/B is: " << A / B << '\n';

    isEqual = (A == B) ? "equal" : "not equal";
    std::cout << "A and B are " << isEqual << '\n';

	return EXIT_SUCCESS;
}

/*
Notes: DONT FORGET (both of us)

- put consts where needed (including zero)
- use default rational constructor where needed
- add +1 to deg when creating vectors

add here if necessary

*/
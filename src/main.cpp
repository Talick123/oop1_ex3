#include "Poly.h"

#include <string>


int main()
{
    auto c1 = std::vector<Rational>{ Rational(2,1),  Rational(1,2), zero , zero ,Rational(7,3), Rational(17,26), Rational(17,234) };
    auto c2 = std::vector<Rational>{ Rational(3,1), zero ,Rational(2,2) };

    auto P1 = Poly(c1);
    auto P2 = Poly(c2);

    Rational tmp_r(3, 1);

    //testing operator<<
    std::cout << "P1 is: " << P1 << '\n';
    std::cout << "P2 is: " << P2 << '\n';

    //testing operators + and -
    std::cout << "P1+P2 is: " << P1+P2 << '\n';
    std::cout << "P1-P2 is: " << P1 - P2 << '\n';

    //testing operator*
    std::cout << "P1*P2 is: " << P1 * P2 << std::endl;
    std::cout << "s*P2 is: " << tmp_r * P2 << std::endl;

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


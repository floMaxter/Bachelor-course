#include <iostream>
#include "Calc.h"

int main()
{
    int g = 0;
    int l = 0;
    std::cout << "Enter polinomial g(x) as integer: ";
    std::cin >> g;
    std::cout << "Enter length: ";
    std::cin >> l;
    
    Calc calc = Calc(g, l);
    long double p = 0;
    std::cout << "Upp" << std::endl;
    for (int i = 0; i < 10; ++i) {
        p += 0.1;
        //std::cout << "(" << p << "; " << calc.calcErr(p) << ")\n" << ", Err: " << calc.calcErr(p) << std::endl;
       /* std::cout << "p = " << p << std::endl;
        std::cout << "Upp: " << calc.upperBound(p) << ", Err: " << calc.calcErr(p) << std::endl;*/
        std::cout << "(" << p << "; " << calc.upperBound(p) << ")" << std::endl;
    }

    std::cout << "Err" << std::endl;
    p = 0;
    for (int i = 0; i < 10; ++i) {
        p += 0.1;
        std::cout << "(" << p << "; " << calc.calcErr(p) << ")" << std::endl;
    }

    return 0;
}
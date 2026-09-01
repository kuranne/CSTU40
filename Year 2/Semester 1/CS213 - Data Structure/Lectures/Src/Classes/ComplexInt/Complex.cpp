#include <iostream>
#include <cmath>
#include "Complex.h"

Complex Complex::operator* (Complex rhs) const
{
    Complex prod;
    prod.re = (re * rhs.re - im * rhs.im);
    prod.im = (re * rhs.im + im * rhs.re);
    return prod;
}

void Complex::print() const
{
    std::cout << this->re << this->im << std::endl;
}

int main() {
    Complex a = Complex(1, 2);
    Complex b = Complex(3, 4);
    Complex c = a * b;

    return 0;
}

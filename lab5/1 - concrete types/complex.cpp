#include "complex.hpp"

complex& complex::operator+=(complex z)
{
    this->re += z.re; // add to re and im
    this->im += z.im;
    return *this;     // and return the result
}

complex& complex::operator-=(complex z)
{
    this->re -= z.re;
    this->im -= z.im;
    return *this;
}

complex operator+(complex a, complex b)
{
    return a += b;
}

complex operator-(complex a, complex b)
{
    return a -= b;
}

bool operator==(complex a, complex b)     // equal
{
     return a.real()==b.real() && a.imag()==b.imag();
}

bool operator!=(complex a, complex b)     // not equal
{
     return !(a==b);
}

#include "vector.hpp"

Vector::Vector(int s)                  // definition of the constructor
     :elem{new double[s]}, sz{s}       // initialize members
{
}

double& Vector::operator[](int i)      // definition of subscripting
{
     return elem[i];
}

int Vector::size()                     // definition of size()
{
     return sz;
}

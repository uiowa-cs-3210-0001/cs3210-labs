#include "complex.hpp"

int main()
{
    complex z = {1,0};
    complex a{ 2.3 };       // construct {2.3,0.0} from 2.3
    complex b{ a + z };
    // ...
    if (a != b)
        a = -b;
}
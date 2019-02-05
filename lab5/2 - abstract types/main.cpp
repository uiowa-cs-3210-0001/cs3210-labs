#include "vector_container.hpp"
#include <iostream>
using namespace std;

void use(Container& c)
{
     const int sz = c.size();
     for (int i=0; i!=sz; ++i)
           cout << c[i] << '\n';
}

int main()
{
    Vector_container c(10);
    use(c);
}

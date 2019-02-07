#include "vector_container.hpp"
#include <iostream>
using namespace std;

void use(Container& c)
{
     const int sz = c.size();
     cout << "Container size: " << sz << endl;
     cout << "Container elements: " << endl;
     for (int i=0; i!=sz; ++i)
           cout << c[i] << '\n';
}

// class Blank_container : public Container
// {
// public:
//      double& operator[](int i) override { throw out_of_range( "no elements" ); }
//      int size() const override { return 0; }
// };

int main()
{
    Vector_container c(10);
    // Blank_container c;
    use(c);
}

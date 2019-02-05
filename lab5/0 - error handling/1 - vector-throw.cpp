#include <iostream>
#include <stdexcept>

using namespace std;


class Vector {
public:
    Vector( int size )
        : size_{ size }, data{ new double[size]{} }
        {}

    double& operator[](int i); // element access: subscripting
    int size() { return this->size_; }

private:
    int size_;    // number of elements
    double* data; // pointer to elements
};


double&
Vector::operator[]( int i )
{
    if ( i < 0 || i >= this->size() ) {
        throw out_of_range( "Vector::operator[]: Index " 
            + to_string( i ) + " is out of range (size: " 
            + to_string( this->size() ) + ")"
            );
    }
    return this->data[i];
}


int main() {
    Vector v( 10 );
    try {
        cout << "v[0]:" << v[0] << endl;
        cout << "v[10]:" << v[10] << endl;
        cout << "v[1]:" << v[1] << endl;
    }
    catch (out_of_range const& x)
    {
        cerr << "\nException: " << x.what() << endl;
    }
}

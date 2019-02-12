#include <iostream>
#include <stdexcept>
using namespace std;


struct complex {
    float real;
    float imag;
    
    complex( float r = 0, float i = 0 )
        : real( r ), imag( i )
    {}

    // static int count;
};

// int complex::count = 0;



class Vector {
public:
    Vector( int size )
        : size_{ size }, data{ new complex[size]{} }
        {}

    complex& operator[](int i)
    {
        if ( i < 0 || i >= this->size() ) {
            throw out_of_range( "Vector::operator[]: Index " 
                + to_string( i ) + " is out of range (size: " 
                + to_string( this->size() ) + ")"
                );
        }

        return this->data[i];
    }
    
    int size() const { return this->size_; }

private:
    int size_;
    complex* data;
};



int main()
{
    try {
        Vector v( 10 );
        v[0] = complex( 42 );
        v[1] = complex( 0, -1 );
    } 
    catch ( exception const& x )
    {
        cerr << x.what() << endl;
    }

    // cout << "complex::count: " << complex::count << endl;
}

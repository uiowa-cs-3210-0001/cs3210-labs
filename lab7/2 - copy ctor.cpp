#include <iostream>
#include <stdexcept>
using namespace std;


struct complex {
    float real;
    float imag;
    int n;
    
    complex( float r = 0, float i = 0 )
        : real( r ), imag( i ), n( ++count )
    {
        cout << "complex::complex#" << this->n << ", total: " << count << endl;
    }

    ~complex()
    {
        --count;
        cout << "complex::~complex#" << this->n << ", total: " << count << endl;
    }

    complex& operator=( complex const& other )
    {
        this->real = other.real;
        this->imag = other.imag;
        return *this;
    }

    static int count;
};

int complex::count = 0;

ostream& operator <<( ostream& out, complex const& c )
{
    return out << "(" << c.real << "," << c.imag << ")";
}



int main()
{
    try {
        complex c1( 42 );
        complex c2( 0, -1 );
        cout << "############ complex::count: " << complex::count << endl;

        complex c3;
        c3 = c1;
        cout << "############ complex::count: " << complex::count << endl;

        // complex c3( c1 );
        // cout << "############ complex::count: " << complex::count << endl;

        cout << "c1: " << c1 << endl;
        cout << "c2: " << c2 << endl;
    } 
    catch ( exception const& x )
    {
        cerr << x.what() << endl;
    }

    cout << "complex::count: " << complex::count << endl;
}

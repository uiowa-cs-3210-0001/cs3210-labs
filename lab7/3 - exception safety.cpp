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


class Vector {
public:
    Vector( int size )
        : size_{ size }, data{ new complex[size]{} }
        {}

    ~Vector()
    {
        delete[] this->data;
        this->data = 0;
    }


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
        cout << "############ complex::count: " << complex::count << endl;

        v[0] = complex( 42 );
        v[1] = complex( 0, -1 );

        cout << "############ complex::count: " << complex::count << endl;

        cout << "v[0]: " << v[0] << endl;
        cout << "v[1]: " << v[1] << endl;
    } 
    catch ( exception const& x )
    {
        cerr << x.what() << endl;
    }

    cout << "complex::count: " << complex::count << endl;
}

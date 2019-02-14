
#include <iostream>
#include <stdexcept>
using namespace std;


struct complex {
    float real;
    float imag;
    
    complex( float r = 0, float i = 0 )
        : real( r ), imag( i )
    {
        cout << "complex::complex(" << this << "), total: " << ++count << endl;
    }

    ~complex()
    {
        cout << "complex::~complex(" << this << "), total: " << --count << endl;
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
    {
        cout << "Vector::Vector(" << this->size_ << ")" << endl;
    }

    ~Vector()
    {
        cout << "Vector::~Vector(" << this->size_ << ")" << endl;
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
        Vector v1( 2 );
        cout << "############ complex::count: " << complex::count << endl;

        Vector v2( 3 );
        v1 = v2;
        cout << "v1.size(): " << v1.size() << endl;        
        cout << "############ complex::count: " << complex::count << endl;
        } 
    catch ( exception const& x )
    {
        cerr << x.what() << endl;
    }

    cout << "complex::count: " << complex::count << endl;
}

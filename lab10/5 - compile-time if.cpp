#include "streaming.hpp"
#include <iostream>
#include <vector>
#include <complex>
#include <type_traits>
#include <cstring>
using namespace std;

struct my_complex
{
    double real;
    double imag;
    my_complex(double r = 0., double i = 0. )
        : real(r), imag(i) 
    {}
    
    my_complex(my_complex const& other)
        : real(other.real), imag(other.imag)
    {}

    friend std::ostream& operator<<( std::ostream& out, my_complex const& c )
    {
        return out << "(" << c.real << "," << c.imag << ")";
    }
};


template< typename T >
void zero_fill( vector<T>& v )
{
    if ( is_trivially_copyable<T>::value ) {
        cout << "memset" << endl;
        memset( &v[0], 0, v.size() * sizeof( T ) );
    }
    else {
        cout << "for loop" << endl;
        for (auto& x : v)
            x = 0;
    }
}


int main()
{
    vector<int> v1({ 10, -1, 42 });
    vector<double> v2({ 10.5, -1.1, 42.7 });
    vector< my_complex > v3({ 
        my_complex( 10.5, 1.0 ), 
        my_complex( -1.1, 0.0 ), 
        my_complex( 42.7, -1.0 ) 
        });

    zero_fill( v1 );
    zero_fill( v2 );
    zero_fill( v3 );

    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;
}

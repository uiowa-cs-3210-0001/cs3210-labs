#include "streaming.hpp"
#include <iostream>
#include <vector>
#include <complex>
#include <type_traits>
#include <iomanip>
using namespace std;

using my_complex = complex<double>;
// typedef complex<double> my_complex;

template< typename T, size_t N > struct my_array
{
    // ...
};

template< typename T > 
struct array255 : my_array<T,255> {};

template< typename T >
void zero_fill(T const& a)
{
    cout 
        << boolalpha
        << ( is_same<T, my_array<int,1024> >::value 
            || is_same<T, my_array<int,255> >::value ) 
        << endl;
    // ...
}



int main()
{
    my_array<int,1024> a1;
    my_array<int,255> a2;
    array255<int> a3;
    zero_fill( a1 );
    zero_fill( a2 );
    zero_fill( a3 );

    vector<int> v1({ 10, -1, 42 });
    vector<double> v2({ 10.5, -1.1, 42.7 });
    vector< my_complex > v3({ 
        my_complex( 10.5, 1.0 ), 
        my_complex( -1.1, 0.0 ), 
        my_complex( 42.7, -1.0 ) 
        });

    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;
}

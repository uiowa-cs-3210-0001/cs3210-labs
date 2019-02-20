#include "streaming.hpp"
#include <iostream>
#include <vector>
#include <complex>
#include <type_traits>
#include <cstring>
using namespace std;

template< typename T >
void zero_fill( vector<T>& v )
{
    for (auto& x : v)
        x = 0;
}


template<>
void zero_fill<int>( vector<int>& v )
{
    memset( &v[0], 0, v.size() * sizeof( int ) );
}


int main()
{
    vector<int> v1({ 10, -1, 42 });
    vector<double> v2({ 10.5, -1.1, 42.7 });
    vector< complex<double> > v3({ 
        complex( 10.5, 1.0 ), 
        complex( -1.1, 0.0 ), 
        complex( 42.7, -1.0 ) 
        });

    zero_fill( v1 );
    zero_fill( v2 );
    zero_fill( v3 );

    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;
}

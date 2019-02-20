#include <iostream>
#include <vector>
#include <complex>
using namespace std;

template< typename T >
T sum( vector<T> const& v )
{
    T result = 0;
    for (auto x : v)
        result += x;

    return result;
}

int main()
{
    cout << sum( vector<int>({ 10, -1, 42 }) ) << endl;
    cout << sum( vector<double>({ 10.5, -1.1, 42.7 }) ) << endl;
    cout << sum( vector< complex<double> >({ 
        complex( 10.5, 1.0 ), 
        complex( -1.1, 0.0 ), 
        complex( 42.7, -1.0 ) 
        }) ) << endl;

    // cout << sum( vector<bool>({ true, false, true }) ) << endl;
}

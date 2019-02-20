#include <iostream>
#include <vector>
#include <complex>
using namespace std;

template< typename Sequence, typename U = typename Sequence::value_type >
U sum( Sequence const& v, U result = 0 )
{
    for (auto x : v)
        result += x;

    return result;
}

template< typename T, unsigned int N >
T sum( T (&a)[N], T result = 0 )
{
    for (auto x : a)
        result += x;

    return result;
}


int main()
{
    int a[] = { 10, -1, 42 };
    cout << sum( a ) << endl;

    cout << sum( vector<int>({ 10, -1, 42 }) ) << endl;
    cout << sum( vector<double>({ 10.5, -1.1, 42.7 }) ) << endl;
    cout << sum( vector< complex<double> >({ 
        complex( 10.5, 1.0 ), 
        complex( -1.1, 0.0 ), 
        complex( 42.7, -1.0 ) 
        }) ) << endl;

    // cout << sum( vector<bool>({ true, false, true }) ) << endl;
}

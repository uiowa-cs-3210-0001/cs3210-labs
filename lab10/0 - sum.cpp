#include <iostream>
#include <vector>
#include <complex>
using namespace std;

int sum( vector<int> const& v )
{
    int result = 0;
    for (auto x : v)
        result += x;

    return result;
}

double sum( vector<double> const& v );
complex<double> sum( vector< complex<double> > const& v );

int main()
{
    cout << sum( vector<int>({ 10, -1, 42 }) ) << endl;
    cout << sum( vector<double>({ 10.5, -1.1, 42.7 }) ) << endl;
    cout << sum( vector< complex<double> >({ 
        complex( 10.5, 1.0 ), 
        complex( -1.1, 0.0 ), 
        complex( 42.7, -1.0 ) 
        }) ) << endl;
}

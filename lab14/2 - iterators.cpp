#include <iostream>
#include <vector>
#include <list>
using namespace std;


template< typename Sequence, typename T >
bool find( 
    Sequence const& seq,
    T const& value
    )
{
    for ( unsigned i = 0; i < seq.size(); ++i )
        if ( seq[i] == value )
            return true;

    return false;
}


int main()
{
    vector<int> v = { 5, 42, -1, 0, 17, 33, 101 };
    cout << find( v, 17 ) << endl;
}

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <set>
using namespace std;


template< typename Sequence, typename T >
bool contains( 
    Sequence const& seq,
    T const& value
    )
{
    for ( auto i = seq.begin(); i != seq.end(); ++i )
        if ( *i == value )
            return true;

    return false;
}


int main()
{
    vector<int> v = { 5, 42, -1, 0, 17, 33, 101 };
    // list<int> l = { 5, 42, -1, 0, 17, 33, 101 };
    // forward_list<int> l = { 5, 42, -1, 0, 17, 33, 101 };
    // set<int> s = { 5, 42, -1, 0, 17, 33, 101 };
    // int a[] = { 5, 42, -1, 0, 17, 33, 101 };
    cout << contains( v, 17 ) << endl;
    cout << contains( v, -5 ) << endl;
}

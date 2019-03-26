#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "streaming.hpp"

using namespace std;

struct temp
{
    int& n;
    bool operator()( int x ) const { return x > n; } 
};


void print_first_greater_than( int n )
{
    vector<int> v = { 5, 10, 17, 19, 42, -1, 0, 17, 33, 101 };

    auto greter_than = [=]( int x ) { return x > n; };
    if ( greter_than( 5 ) )
        cout << "yes";

    auto it = find_if( 
        v.begin(), v.end(), 
        greter_than
        // temp{ n }
        );

    if ( it != v.end() ) {
        cout << *it << endl;
        cout << v << endl;
    }
    else {
        // v.insert( it, 18 );
        cout << "not found" << endl;
        cout << v << endl;
    }

    cout << "pos: " << ( it - v.begin() ) << endl;

}


int main()
{
    vector<int> v = { 5, 10, 17, 19, 42, -1, 0, 17, 33, 101 };

    for_each(
        v.begin(), v.begin() + 5, 
        []( int x ) { cout << x << ", "; } 
        );

    // for ( auto& x: v )
    //     cout << x << ", ";

}

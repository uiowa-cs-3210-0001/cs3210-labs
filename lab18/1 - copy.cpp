#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "streaming.hpp"

using namespace std;

int main()
{
    vector<int> v = { 17, 42, -1, 0, 17, -33, -101 };
    list<int> l;
    copy( v.begin(), v.end(), std::back_inserter( l ) );
    cout << l << endl;

    // copy( v.begin(), v.end(), std::ostream_iterator<int>( cout, ", " ) );
    // cout << endl;

    // int array[100];
    // copy( v.begin(), v.end(), array );

    // copy_if( l.begin(), l.end(), std::ostream_iterator<int>( cout, " " ),
    //     []( auto x ) { return x > 0; } 
    // );

    // cout << endl;
}

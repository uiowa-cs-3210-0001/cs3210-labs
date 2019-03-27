#include <iostream>
#include <vector>
#include <algorithm>
#include "streaming.hpp"

using namespace std;

int main()
{
    vector<int> v = { 17, 42, -1, 0, 17, -33, -101 };
    auto n = count( v.begin(), v.end(), 17 );
    cout << n << endl;

    auto m = count_if( v.begin(), v.end(), []( auto x ) { return x < 0; } );
    cout << m << endl;
}

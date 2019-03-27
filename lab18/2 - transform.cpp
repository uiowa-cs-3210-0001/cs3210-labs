#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "streaming.hpp"

using namespace std;

int main()
{
    vector<int> v = { 5, 42, -1, 0, 17, 33, 101 };
    transform( v.begin(), v.end(), v.begin(), 
        []( int x ) { return -x; }
        // std::negate<int>()
    );

    cout << v << endl;

    vector<int> v2 = { 5, 42, -1, 0, 17, 33, 101 };
    vector<int> result;
    transform( v.begin(), v.end(), v2.begin(), std::back_inserter( result ), 
        []( int x, int y ) { return x + y; }
    );

    cout << result << endl;
}

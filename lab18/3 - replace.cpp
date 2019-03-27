#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "streaming.hpp"

using namespace std;

int main()
{
    vector<int> v = { 17, 42, -1, 0, 17, -33, 101 };
    replace( v.begin(), v.end(), 17, 77 ); 
    cout << v << endl;

    // replace_if( v.begin(), v.end(), []( auto x ) { return x < 0; }, -77 ); 
    // cout << v << endl;
}

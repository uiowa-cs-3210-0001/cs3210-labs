#include <iostream>
#include <vector>
#include <algorithm>
#include "streaming.hpp"

using namespace std;

int main()
{
    vector<int> v = { 5, 42, -1, 0, 17, 33, 101 };
    auto it = find( v.begin(), v.end(), 17 );
    cout << *it << endl;

    v.erase( it );
    cout << v << endl;

    // auto it = find_if( v.begin(), v.end(), /* x > 17 */ );

}


// struct greater_than {
//      int val;
//      greater_than(int v) : val{v} {}
//      bool operator()(int v) const { return v>val; }
// };

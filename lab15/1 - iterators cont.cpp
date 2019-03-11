#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <forward_list>
#include <set>


// template< typename Iterator, typename T >
// Iterator find( Iterator first, Iterator last, T const& value )
// {
//     for (; first != last; ++first)
//         if ( *first == value )
//             break;

//     return first;
// }


int main()
{
    std::vector<int> v = { 5, 42, -1, 0, 17, 33, 101 };
    // list<int> l = { 5, 42, -1, 0, 17, 33, 101 };
    // forward_list<int> l = { 5, 42, -1, 0, 17, 33, 101 };
    // set<int> s = { 5, 42, -1, 0, 17, 33, 101 };
    // int a[] = { 5, 42, -1, 0, 17, 33, 101 };
    auto i = std::find( v.begin(), v.end(), 17 );
    std::cout << ( i != v.end() ? "found" : "not found" ) << std::endl;
}

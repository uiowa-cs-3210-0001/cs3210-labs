#include "streaming.hpp"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <list>
#include <forward_list>
#include <set>

namespace cs3210 {

template< typename Iterator, typename OutputIterator >
OutputIterator copy( Iterator first, Iterator last, OutputIterator result )
{
    for ( ; first != last; ++first, ++result )
        *result = *first;

    return result;
}

}


int main()
{
    int a[] = { 5, 42, -1, 0, 17, 33, 101 };

    std::vector<int> v( 7 );
    cs3210::copy( std::begin( a ), std::end( a ), v.begin() );

    // cs3210::copy( std::begin( a ), std::end( a ), std::back_inserter( v ) );

    // cs3210::copy( std::begin( a ), std::end( a ), std::ostream_iterator<int>( std::cout, " " ) );

    // list<int> l = { 5, 42, -1, 0, 17, 33, 101 };
    // forward_list<int> l = { 5, 42, -1, 0, 17, 33, 101 };
    // set<int> s = { 5, 42, -1, 0, 17, 33, 101 };
    std::cout << v << std::endl;
}

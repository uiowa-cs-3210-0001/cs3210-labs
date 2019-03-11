#ifndef CS3210_STREAMING_HPP
#define CS3210_STREAMING_HPP

#include <vector>
#include <iosfwd>

template< typename T >
std::ostream& operator<<( std::ostream& out, std::vector<T> const& v )
{
    for (auto x : v)
        out << x << " ";

    return out;
}

#endif // CS3210_STREAMING_HPP

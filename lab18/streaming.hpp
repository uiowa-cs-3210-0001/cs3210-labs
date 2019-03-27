#ifndef CS3210_STREAMING_HPP
#define CS3210_STREAMING_HPP

#include <iosfwd>

template< typename C, typename = typename C::iterator >
std::ostream& operator<<( std::ostream& out, C const& c )
{
    for (auto x : c)
        out << x << " ";

    return out;
}


#endif // CS3210_STREAMING_HPP

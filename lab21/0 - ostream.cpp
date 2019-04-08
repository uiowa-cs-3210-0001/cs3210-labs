#include <iostream>
using namespace std;

template< typename T >
void write( std::ostream& out, T const& x )
{
    out << x;
}


int main()
{
    write( std::cout, 17 );
    write( std::cout, "Hello there" );
    write( std::cout, '\n' );
    // write( std::cout, Point{ 10, 15 } );
    // write( std::cout, '\n' );

    // write( std::cout, "🎉" );
}


// struct Point { int x, y; };

// std::ostream& operator<<( std::ostream& out, Point const& p )
// {
//     return out << '(' << p.x << ',' << p.y << ')';
// }


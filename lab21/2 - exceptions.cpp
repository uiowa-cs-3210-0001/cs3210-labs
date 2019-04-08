#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>
using namespace std;

template< typename T >
void write( std::ostream& out, T const& x )
{
    out << x;
}


void write_to_stream( std::ostream& out )
{
    write( out, 17 );
    write( out, "Hello there!" );
    write( out, '\n' );
    // write( out, Point{ 10, 15 } );
    // write( out, '\n' );

    write( out, "🎉" );
}


int main()
{
    try {
        std::ofstream out;
        out.exceptions( std::ofstream::failbit );
        out.open( "output.txt" );
        write_to_stream( out );
    } 
    catch ( std::ios_base::failure const& x )
    {
        std::cerr << x.what() << std::endl;
    }
}


// struct Point { int x, y; };

// std::ostream& operator<<( std::ostream& out, Point const& p )
// {
//     return out << '(' << p.x << ',' << p.y << ')';
// }


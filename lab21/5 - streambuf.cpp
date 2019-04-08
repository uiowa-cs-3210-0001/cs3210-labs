#include <streambuf>
#include <iostream>
using namespace std;

struct null_buffer : std::streambuf {
    int overflow( int c ) override { return c; }
};


class null_stream : public std::ostream {
    null_buffer buf;
public: 
    null_stream() : std::ostream( &buf ) {} 
};


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
    write( out, "🎉" );
    write( out, '\n' );
}

int main()
{
    int n;
    std::cin >> n;

    null_stream null;
    write_to_stream( n == 0 ? null : std::cout );
}

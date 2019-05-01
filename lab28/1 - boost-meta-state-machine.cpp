#include <boost/lexical_cast.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace boost;


struct point
{
    int x, y;
    
    friend bool operator==( point const& l, point const& r ) 
        { return l.x == r.x && l.y == r.y; }
};


std::ostream& operator<<( std::ostream& out, point const& p )
{
    return out << "(" << p.x << "," << p.y << ")";
}


std::istream& operator>>( std::istream& in, point& result )
{
    char lparen, comma, rparen; 
    point p;
    if ( !( in >> lparen >> p.x >> comma >> p.y >> rparen ) 
            || lparen != '(' || comma != ',' || rparen != ')'
            )
        {
            if ( !( in.exceptions() & std::ios_base::failbit ) )
            {
                in.setstate( std::ios_base::failbit );
                return in;
            }

            throw std::runtime_error( "Error reading Point from stream" );
        }

    result = p;
    return in;
}



int main()
{
    cout << lexical_cast<int>( "42" ) << endl;
    cout << lexical_cast<string>( 42 ) << endl;

    cout << lexical_cast<string>( point{ 10, 21 } ) << endl;
    cout << lexical_cast<point>( "(10,21)" ) << endl;

    point p{ -1, 17 };
    cout << ( lexical_cast<point>( lexical_cast<string>( p ) ) == p ) << endl;
}

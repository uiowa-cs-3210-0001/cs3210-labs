#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


template< typename S >
void do_stuff( S& s )
{
    std::copy( s.begin(), s.end(), std::ostreambuf_iterator( cout ) );
    cout << endl;

    std::transform( s.begin(), s.end(), s.begin(), []( char c ) { return std::toupper( c ); } );
    std::copy( s.begin(), s.end(), std::ostreambuf_iterator( cout ) );
    cout << endl;

    cout << "size: " << s.size() << endl;

    s.push_back( '!' );
    std::copy( s.begin(), s.end(), std::ostreambuf_iterator( cout ) );
    cout << endl;

    // cout << "substr: " << s.substr( 0, 5 ) << endl;

    // s.replace( 7, 5, "everyone" );
    // cout << "substr: " << s << endl;

    // auto pos = s.find( "everyone" );
    // cout << "pos: " << pos << endl;

    // cout << "strlen: " << strlen( s.c_str() ) << endl;    
}

 
int main()
{
    string s1( "Hello, world" );
    vector<char> v( { 'H', 'e', 'l', 'l', 'o', ',', ' ', 'w', 'o', 'r', 'l', 'd' } );
    
    cout << "string:" << endl;
    do_stuff( s1 );

    cout << "\nvector:" << endl;
    do_stuff( v );
}

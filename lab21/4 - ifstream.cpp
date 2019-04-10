#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

template< typename T >
T read( std::istream& in )
{
    T x;
    in >> x;
    return x;
}


void read_from_stream( std::istream& in )
{
    auto c = read<char>( in );
    std::cout << "Read: " << c << endl;

    auto c2 = read<char>( in );
    std::cout << "Read: " << c2 << endl;

    // auto p = read<Point>( std::cin );
    // std::cout << "Read: " << p << endl;
}


int main()
{

    std::ifstream in( "input.txt" );
    read_from_stream( in );

    // std::stringstream ss( "cd" );
    // read_from_stream( ss );
}

// struct Point { int x, y; };

// std::istream& operator>>( std::istream& in, Point& result )
// {
//     char lparen, comma, rparen; 
//     Point p;
//     if ( !( in >> lparen >> p.x >> comma >> p.y >> rparen ) 
//             || lparen != '(' || comma != ',' || rparen != ')'
//             )
//         {
//             if ( !( in.exceptions() & std::ios_base::failbit ) )
//             {
//                 in.setstate( std::ios_base::failbit );
//                 return in;
//             }

//             throw std::runtime_error( "Error reading Point from stream" );
//         }

//     result = p;
//     return in;
// }

// std::ostream& operator<<( std::ostream& out, Point const& p )
// {
//     return out << '(' << p.x << ',' << p.y << ')';
// }

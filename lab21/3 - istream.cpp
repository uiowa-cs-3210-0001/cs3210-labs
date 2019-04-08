#include <iostream>
using namespace std;

template< typename T >
T read( std::istream& in )
{
    T x;
    in >> x;
    return x;
}


int main()
{
    // auto c = read<char>( std::cin );
    // std::cout << "Read: " << c << endl;
    // std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );

    // auto c2 = read<char>( std::cin );
    // std::cout << "Read: " << c2 << endl;

    // auto s = read<string>( std::cin );
    // std::cout << "Read: " << s << endl;

    // std::string line;
    // std::getline( std::cin, line );
    // std::cout << "Read: " << line << endl;

    // auto p = read<Point>( std::cin );
    // std::cout << "Read: " << p << endl;

}

// struct Point { int x, y; };

// std::istream& operator>>( std::istream& in, Point& result )
// {
//     char lparen, comma, rparen; 
//     Point p;
//     if ( !( in >> lparen >> p.x >> comma >> p.y >> rparen ) 
//             || lparen != '(' || comma != ',' || rparen != ')'
//             )
//         throw std::runtime_error( "Error reading Point from stream" );

//     result = p;
//     return in;
// }

// std::ostream& operator<<( std::ostream& out, Point const& p )
// {
//     return out << '(' << p.x << ',' << p.y << ')';
// }

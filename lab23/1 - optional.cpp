#include <iostream>
#include <optional>
#include <string>
using namespace std;


optional<int> as_int( std::string const& str )
{
    try {
        std::size_t pos = 0;
        int const result = std::stoi( str, &pos );
        return pos == str.length()
            ? result 
            : optional<int>();
    }
    catch( std::exception const& )
    {
        return optional<int>();
    }
}


std::ostream& operator<<( std::ostream& out, optional<int> const& v )
{
    if ( v )
        return out << *v;

    return out << "no value";
}


int main()
{
    cout << as_int( "5" ) << endl;
    cout << as_int( "17" ) << endl;
    cout << as_int( "17addfsd" ) << endl;
}

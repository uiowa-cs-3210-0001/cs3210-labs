#include <iostream>
#include <regex>
#include <optional>
using namespace std;

regex const us_postal_code_re{ R"((\w{2})\s*(\d{5})(-(\d{4}))?)" };

struct postal_code
{
    string state;
    string zip;
    string zip_ext;

    friend ostream& operator<<( ostream& out, postal_code const& pc )
    {
        out << pc.state << " " << pc.zip;
        if ( !pc.zip_ext.empty() )
            out << "-" << pc.zip_ext;
        return out;
    }
};


optional<postal_code> parse( string const& str )
{
    smatch matches;
    if ( regex_search( str, matches, us_postal_code_re ) ) {
        return postal_code{ matches[1], matches[2], matches[4] };
    }

    return {};
}


void parse_and_print( string const& str )
{
    if ( auto pc = parse( str ) )
        cout << *pc << endl;
    else
        cout << "'" << str << "' is not a postal code" << endl;
}


int main()
{
    parse_and_print( "" );
    parse_and_print( "IA 52240" );
    parse_and_print( "IA 52240-3333" );
}

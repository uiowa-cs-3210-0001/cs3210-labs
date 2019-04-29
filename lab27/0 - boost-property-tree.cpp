#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <string_view>
#include <string>
#include <iostream>

using namespace std;
using namespace boost::property_tree;


ptree load_settings( string const& filename )
{
    ptree result;
    read_json( filename, result );
    return result;
}


int main()
{
    auto settings = load_settings( "settings.json" );
    cout << settings.get<bool>( "debug.eat" ) << endl;

    settings.put<bool>( "debug.eat", false );
    cout << settings.get<bool>( "debug.eat" ) << endl;
}

#include <iostream>
#include <string>
#include <string_view>
using namespace std;


string cat( string_view s1, string_view s2 )
{
     string result;
     result.reserve( s1.size() + s2.size() );
     std::copy( s1.begin(), s1.end(), std::back_inserter( result ) );
     std::copy( s2.begin(), s2.end(), std::back_inserter( result ) );
     return result;
}


int main()
{
    string king = "Harold ";
    cout << cat( "Hello,", " world" ) << endl;
    cout << cat( king, "William" ) << endl;
    cout << cat( king, king ) << endl;

    // using namespace std::literals::string_view_literals;
    // cout << cat( "Edward "sv, "Stephen"sv ) << endl;
    // cout << cat( "Canute "sv, king ) << endl;
}

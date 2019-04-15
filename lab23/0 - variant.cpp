#include <iostream>
#include <algorithm>
#include <array>
#include <variant>
using namespace std;


struct ip_v4_address {
    typedef std::array<unsigned char,4> bytes_type;
    bytes_type address;

    ip_v4_address( bytes_type const& addr ) : address( addr ) {}    

    friend std::ostream& operator<<( std::ostream& out, ip_v4_address const& addr )
    {
        std::copy( addr.address.begin(), addr.address.end(),
            std::ostream_iterator<int>( out, "." ) );
        return out;
    }
};

struct ip_v6_address {
    typedef std::array<unsigned char,16> bytes_type;
    bytes_type address;

    ip_v6_address( bytes_type const& addr ) : address( addr ) {}    

    friend std::ostream& operator<<( std::ostream& out, ip_v6_address const& addr )
    {
        std::copy( addr.address.begin(), addr.address.end(),
            std::ostream_iterator<int>( out, ":" ) );
        return out;
    }
};


using ip_address = std::variant<ip_v4_address,ip_v6_address>;

std::ostream& operator<<( std::ostream& out, ip_address const& addr )
{
    if ( auto a = get_if<ip_v4_address>( &addr ) )
        return out << *a;
    
    if ( auto a = get_if<ip_v6_address>( &addr ) )
        return out << *a;

    return out;
}

 
int main()
{
    ip_v4_address v4( { 127, 0, 0, 1 } );
    ip_v6_address v6( { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 } );

    cout << "v4: " << v4 << endl;
    cout << "v6: " << v6 << endl;

    ip_address addr( v4 );
    cout << "ip_address: " << addr << endl;
}

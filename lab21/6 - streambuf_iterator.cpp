#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    std::ifstream in( "input.txt" );
    std::istreambuf_iterator<char> it( in.rdbuf() );
    std::istreambuf_iterator<char> eos;
    std::copy( it, eos, std::ostreambuf_iterator( cout ) );
    // std::replace_copy( it, eos, std::ostreambuf_iterator( cout ), 'a', 'A' );
}

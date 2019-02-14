#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdio>
#include <cerrno>
using namespace std;


void copy_file( string src, string dst )
{
    FILE* src_file;
    src_file = fopen( src.c_str(), "rx" );
    if ( !src_file )
        throw runtime_error( "Can't open source file: "s + strerror( errno ) );

    FILE* dst_file;
    dst_file = fopen( dst.c_str(), "wx" );
    if ( !dst_file )
        throw runtime_error( "Can't open destination file: "s + strerror( errno ) );

    char c;
    while ( ( c = fgetc( src_file ) ) != EOF )
        fputc( c, dst_file );

    fclose( dst_file );
    fclose( src_file );
}


int main()
{
    try {
        copy_file( "a.txt", "b.txt" );
    }
    catch ( exception const& x )
    {
        cerr << x.what() << endl;
    }
}

#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdio>
#include <cerrno>
using namespace std;

class file_handle
{
public:
    file_handle( FILE* h )
        : handle( h )
    {}

    ~file_handle()
    {
        if ( this->handle )
            fclose( this->handle );
    }

    operator FILE*() const { return this->handle; }

private:
    FILE* handle;
};


void copy_file( string src, string dst )
{
    file_handle src_file( fopen( src.c_str(), "rx" ) );
    if ( !src_file )
        throw runtime_error( "Can't open source file: "s + strerror( errno ) );

    file_handle dst_file( fopen( dst.c_str(), "wx" ) );
    if ( !dst_file )
        throw runtime_error( "Can't open destination file: "s + strerror( errno ) );

    char c;
    while ( ( c = fgetc( src_file ) ) != EOF )
        fputc( c, dst_file );
}


void try_copy()
{
    try {
        copy_file( "a.txt", "b.txt" );
    }
    catch ( exception const& x )
    {
        cerr << x.what() << endl;
    }
}

int main()
{
    for ( int i = 0; i < 10000; ++i )
        try_copy();
}
